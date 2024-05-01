//+------------------------------------------------------------------+
//|                                                      PhiFiEA.mq5 |
//|                                                  Clesson Roberto |
//|                                             https://www.mql5.com |
//+------------------------------------------------------------------+
#property copyright "Copyright 2024, Clesson Roberto"
#property link      "https://https://clessonr.github.io/"
#property version   "1.00"

#include <trade/trade.mqh>

#resource  "\\Files\\Sounds\\alert.wav"

input double Lot = 0.01;
input ENUM_TIMEFRAMES Timeframe = PERIOD_CURRENT;
input int SlPoints = 280;
input bool TrailingStop = false;
input bool indicator_mode = true;
input bool sound_alert = true;

// Define your desired trading hours
int start_hour = 8;   // Example: 08:00
int end_hour = 13;    // Example: 13:00



enum ENUM_MY_OPTIONS
{
    um,
    um_e_meio,
    dois
};

input ENUM_MY_OPTIONS TakeLevel = dois;


int handleMFI;
int handleEMA144;
int handleEMA610;
int barsTotal;
CTrade trade; 

// Define the names corresponding to the ENUM values
double MyOptionNames[] = {1, 1.5,2};
double take_multiplier = MyOptionNames[TakeLevel];

double TpPoints = SlPoints * take_multiplier;
double ema_distance = SlPoints/4;



//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
  {
//---
   Print("Take Profit: ",TpPoints, " Stop ", SlPoints);
   
   Print("PhiFiEA Initialized");
   
   handleMFI = iMFI(NULL,Timeframe,34,VOLUME_TICK);
   handleEMA144 = iMA(NULL,Timeframe,144,0,MODE_EMA,PRICE_CLOSE);
   handleEMA610 = iMA(NULL,Timeframe,610,0,MODE_EMA,PRICE_CLOSE);
   
   
   
//---
   return(INIT_SUCCEEDED);
  }
//+------------------------------------------------------------------+
//| Expert deinitialization function                                 |
//+------------------------------------------------------------------+
void OnDeinit(const int reason)
  {
//---
   Print("De Init ID:", reason);
  }
//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick()
  {
//---
   
   
      if(TrailingStop){
      for(int i = 0; i < PositionsTotal(); i++){
         ulong posTicket = PositionGetTicket(i);
         
         double bid = SymbolInfoDouble(_Symbol, SYMBOL_BID);
         double ask = SymbolInfoDouble(_Symbol, SYMBOL_ASK);
         
         double posPriceOpen = PositionGetDouble(POSITION_PRICE_OPEN);
         double posSl = PositionGetDouble(POSITION_SL);
         double posTp = PositionGetDouble(POSITION_TP);
         
         if(PositionGetInteger(POSITION_TYPE) == POSITION_TYPE_BUY)
         {
            if(bid> posPriceOpen + SlPoints * _Point)
            {
               double sl = posPriceOpen;
               sl = NormalizeDouble(sl, _Digits);
               if(sl > posSl){
                  trade.PositionModify(posTicket, sl, posTp);
                  Sleep(1200000);
               }
            
            }
         
         
         }
         else if(PositionGetInteger(POSITION_TYPE) == POSITION_TYPE_SELL)
         {
            if(ask < posPriceOpen - SlPoints * _Point)
            {
               double sl = posPriceOpen;
               sl = NormalizeDouble(sl,_Digits);
               if(sl < posSl){
                  trade.PositionModify(posTicket, sl, posTp);
                  Sleep(1200000);
               }
            }
         }
         
         
      }
      
   }
   
   double mfi[];
   double ema144[];
   double ema610[];
   
   
   
   CopyBuffer(handleMFI,0,0,1,mfi);
   CopyBuffer(handleEMA610,0,0,1,ema610);
   CopyBuffer(handleEMA144,0,0,1,ema144);
   
   double v_ema144 = ema144[0];
   v_ema144 = NormalizeDouble(v_ema144,_Digits);
   
   
   double v_ema610 = ema610[0];
   v_ema610 = NormalizeDouble(v_ema610,_Digits);
   
   
   double mfi_value = mfi[0];
   mfi_value = NormalizeDouble(mfi_value,_Digits);
   
   //Print("Distance: ",(MathAbs(v_ema144 - v_ema610)/_Point));
   
   if( (MathAbs(v_ema144 - v_ema610)/_Point) > ema_distance && isOutside(v_ema144,v_ema610) && IsPositionOpen() == false) { // The distance between the MA's is decent
   
      double currentPricenow = GetCurrentCandlePrice();
      
      if(v_ema144 > v_ema610 && currentPricenow > v_ema610 && mfi_value <= 40)// Long Trend
      { 
         double currentAsk = GetCurrentAskPrice();
         
         if(currentPricenow <= v_ema144) // First Touch in the SMA after a long trend;
         {
            
            if(indicator_mode){
               Print("Buy it");
               if(sound_alert){
                  string message;
                  StringConcatenate(message,"Buy Trigger on: ",_Symbol);
                  
                  SendNotification(message);
                  PlaySound("\\Files\\Sounds\\alert.wav");
                  Sleep(5000);
                }
            
            }
            else{
            executeOrder("buy");
            }
      }
      }
      

      if(v_ema610 > v_ema144 && currentPricenow < v_ema610 && mfi_value >= 60) //Short Trend
      {
      Print("Trigger Venda");
      
      if(currentPricenow >= v_ema144) // First Touch in the SMA after a short trend;
         {  
            if(indicator_mode){
               Print("Sell it");
                if(sound_alert){
                  string message;
                  StringConcatenate(message,"Buy Trigger on: ",_Symbol);
                  SendNotification(message);
                  PlaySound("\\Files\\Sounds\\alert.wav");
                  Sleep(5000);
                }
            
            }
            else{
            executeOrder("sell");
            }
      }
      
         
      
      }
      }
      
      


   
   /*Print("ema144:",v_ema144);
   
   
   Print(MathAbs(v_ema144 - v_ema610)/_Point);
   double currentPrice = GetCurrentCandlePrice();
   Print("Current candle price: ", currentPrice);
   
   // Get the current ask price
   double currentAsk = GetCurrentAskPrice();
   Print("Ask Price:",currentAsk);
   
   
   // Get the current bid price
   double currentBid = GetCurrentBidPrice();
   Print("Bid Price:", currentBid);
   */
   }
   
  
//+------------------------------------------------------------------+

void executeOrder(string order_type){
   if(order_type=="buy"){
   
      Print("Buy Signal");
      double entry = SymbolInfoDouble(NULL, SYMBOL_ASK); // Getting the ask price
      entry = NormalizeDouble(entry,_Digits); // Normalizing to currency decimal places
      
      double tp = entry + (TpPoints * _Point); // Number of points in currency
      tp = NormalizeDouble(tp, _Digits);
      
      double sl = entry - (SlPoints * _Point);
      sl = NormalizeDouble(sl, _Digits);
      trade.Buy(Lot,NULL,entry,sl,tp,"Bought");

   }
   else{
      Print("Sell Signal");
      
      double entry = SymbolInfoDouble(NULL, SYMBOL_BID); // Getting the bid price
      entry = NormalizeDouble(entry,_Digits); // Normalizing to currency decimal places
      
      double tp = entry - TpPoints * _Point; // Number of points in currency
      tp = NormalizeDouble(tp, _Digits);
      
      double sl = entry + SlPoints * _Point;
      sl = NormalizeDouble(sl, _Digits);
      
      
      trade.Sell(Lot,NULL,entry,sl,tp,"Sold");
}
   

}



bool IsPositionOpen()
{
    int totalPositions = PositionsTotal();
    
    // If there are no positions, return false
    if(totalPositions == 0)
        return false;
    
    // Loop through all positions
    for(int i = 0; i < totalPositions; i++)
    {
        // Get position ticket
        ulong ticket = PositionGetTicket(i);
        
        // If the position ticket is valid (not zero), return true
        if(ticket != 0)
            return true;
    }
    
    // No valid position tickets found, return false
    return false;
}

double GetCurrentCandlePrice()
{
    double priceBuffer[1];
    int copied = CopyClose(Symbol(), Period(), 0, 1, priceBuffer);
    
    // Check if the price was successfully copied
    if(copied == 1)
    {
        return priceBuffer[0];
    }
    else
    {
        // Handle error if the price couldn't be copied
        Print("Error: Unable to get current candle price.");
        return 0.0; // Or any other appropriate value to indicate error
    }
}

double GetCurrentBidPrice()
{
    return SymbolInfoDouble(Symbol(), SYMBOL_BID);
}

// Get the current ask price
double GetCurrentAskPrice()
{
    return SymbolInfoDouble(Symbol(), SYMBOL_ASK);
}

bool isOutside(double current_ema144, double current_ema610)
{
   double currentPrice = GetCurrentCandlePrice();
   if( current_ema144 > currentPrice && currentPrice > current_ema610 ) // Up Trend, but is inside the mean's;
   {
      return false;
   }
   else if (current_ema610 > currentPrice && currentPrice > current_ema144)// Down Trend, but is inside the mean's;
   {
      return false;
   }
   else
   {
      return true;
   }

}



// Check if the current hour falls within the desired range
bool IsTimeInRange()
{
    datetime current_time = TimeCurrent(); // Get current time
    int current_hour = (int)MathFloor(current_time / 3600) % 24; // Calculate current hour
    return (current_hour >= start_hour && current_hour < end_hour);
}

