#My main bashrc file 

#
# ~/.bashrc
#

#Making neovim the default editor
export EDITOR='nvim'
export VISUAL='nvim'

#Cleanup orphaned packages
alias cleanup='sudo pacman -Rns $(pacman -Qtdq)'

#fix obvious typo's
alias cd..='cd ..'
alias pdw="pwd"
alias udpate='sudo pacman -Syyu'
alias upate='sudo pacman -Syyu'
alias updte='sudo pacman -Syyu'
alias updqte='sudo pacman -Syyu'
alias upqll="paru -Syu --noconfirm"
alias upal="paru -Syu --noconfirm"
alias packages='pacman -Qq | wc -l

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

# Terminal prompt profile

PS1="\[\e[31;40m\][\[\e[m\]\[\e[35;40m\]\u\[\e[m\]\[\e[31;40m\]]\[\e[m\]\[\e[36m\]\w\[\e[m\]\[\e[33m\]\\$\[\e[m\]: "

#Default System Aliases
alias c="clear"
alias updt="sudo pacman -Syu"
alias get="sudo pacman -S"
alias find="sudo pacman -Ss"
alias ee="exit"
alias ccache="sudo pacman -Sc"
alias bashrc='sudo nvim ~/.bashrc'
alias version='sudo pacman -Q'
alias v='nvim'
alias ls='ls --color=auto'
alias purge='sudo pacman -Rns'
# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/home/clesson/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/home/clesson/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/home/clesson/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/home/clesson/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<



