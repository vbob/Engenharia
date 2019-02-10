%{ 
Questão I – Projetar um filtro FIR passa baixas utilizando a janela de Hamming para frequência de
amostragem Fs = 8000Hz e Fc = 1750Hz. 
Repetir filtro para Janela de Blackman modo a aumentar a atenuação dos sinais na banda de rejeição. 
Comparar os resultados. 
Aplicar os sinais abaixo ao filtro. 
Plotar o sinal de entrada e seu respectivo espectro de frequência. 
Modulo e fase dos filtros projetados bem como os sinais filtrados e seus respectivos espectros de frequências. 
Discutir os resultados baseados na teoria de filtros. 
%}

% FILTRO
fs = 8000;
fc = 1750;

N = 200;

Wn = (2/fs)*fc;
b = fir1(N, Wn, 'low', hamming(N+1));

fvtool(b, 1, 'Fs', fs) 

% SINAL ORIGINAL
t=0:0.1:100;
f1=1000; % freqüência dentro da banda de passagem
f2=3000; % freqüência dentro da banda de rejeição


x = 4*sin((2*pi*f1*t/fs))+sin((2*pi*f2*t/fs)); % Sinal com ruído

ax1 = subplot (2, 1, 1);
plot(ax1, t, x);
title(ax1, 'Sinal Original');

% SINAL FILTRADO
y = filter(b, 1, x);

ax2 = subplot (2, 1, 2);
plot(ax2, t, y);
title(ax2, 'Sinal Filtrado');
