# PBL3-Osciloscopio
- A ideia do terceiro problema é a construção de oscilóscopio digital, com visualização de dados de um conversor ADC em tempo real. Por conta da situação de estamos enfrentando, os dados são adquiridos de um arquivo de texto, simulando valores que seriam lidos do conversor ADC.
	
## Objetivos
- Compreender a comunicação entre o processador e um barramento;
- Identificar características de operação e restrições em projetos de sistemas digitais;
- Compreender a integração de sistemas digitais em nível de arquitetura.

## Desenvolvimento
- Com o conhecimento adiquirido sobre pipe e sincronização de processos a partir da resolução do problema produtor-consumidor, foi
	desenvolvido um código na linguagem C.
- Para a plotagem do ociloscópio foi utlizada a ferramenta GNUPlot.
- Todo o desenvolvimento se deu em uma máquina virtual para o Raspberry Pi.

## Como executar
- Para a instalação da máquina virtual no Windows basta seguir este tutorial: [link](https://www.youtube.com/watch?v=gZ9a6H5-My0&feature=youtu.be).
- O GNUPlot deve ser instalado no Raspberry da máquina virtual, este pode ser encontrado para download no seu site principal http://www.gnuplot.info/download.html.
- Para compilar e executar o produto:
```
	$ gcc pbl.c -o pbl -lm
 	$ ./pbl
```
## Contribuidores
@elvisserafim
@karolynelima
