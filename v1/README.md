

A mágica começa no "roda_all.sh", que chama o "bin/roda_graphs.sh" para todo nome que estiver em "res/algorithms".

roda_graphs usará como auxiliar o "vector_create" que é um binario escrito em C++ que gera vetores ints e doubles (entre 0 e 1) nas diferentes configurações exigidas pelos testes.

todas as saidas estao em /out

em cada pasta se encontrará um gráfico e o .dat de entrada que gerou o grafico.

na pasta bin/ se encontram os 3 scripts plotters usados no trabalho: log_plotter, quadratic_plotter e linear_plotter. A diferença entre eles é a função de ajuste utilizada. 

Ao refatorar alguns codigos tentei flexibilizar ao maximo os diretorios mas peço desculpas se houver ainda algum hard-coded que exija re-configuração para rodar propriamente em outra maquina.

Obrigado! 
