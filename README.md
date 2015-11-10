# Zombieland
Para inicializar o simulador apocalíptico, primeiro instale a ferramenta Docker e em seguida, execute o script `install.sh`.

### zombie
Software que força o processo filho entrar em modo zombie.

### zattack
Software capaz de encontrar processos zombies e matá-los.

### crontask.sh
Script responsável por realizar o agendamento dos softwares zattack e zombie no crontab.

### Dockerfile
Conjunto de instruções para criação do container que simulará a infestação zombie.

### zombieland
System V init script capaz de gerenciar o container responsável por controlar os softwares zombie e zattack.

### install.sh
Script responsável pela criação da imagem do container, instalação do script de inicialização zombieland e criação dos links simbólicos do script zombieland nos runlevels.
