# My main .bashrc file for arch-linux distros;
#
# ~/.bashrc
#


#Making neovim the default editor
export EDITOR='/usr/bin/vim'
export VISUAL='/usr/bin/vim'

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
alias packages='pacman -Qq | wc -l'

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

# Terminal prompt profile

# PS1="\[\e[31;40m\][\[\e[m\]\[\e[35;40m\]\u\[\e[m\]\[\e[31;40m\]]\[\e[m\]\[\e[36m\]\w\[\e[m\]\[\e[33m\]\\$\[\e[m\]: "

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
alias mirrors='sudo nvim /etc/pacman.d/mirrorlist'
alias ctlstatus='sudo systemctl status'
alias yd='yt-dlp'
