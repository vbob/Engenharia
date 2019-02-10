f1=1000; %frequencia dentro da banda de passagem 
f2=3000; %frequencia dentro da banda de rejeição   
t=[0:1:1000];   
fs=8000; %frequencia de amostragem 
fc=1750; %frequencia de corte   

x=4*sin((2*pi*f1*t/fs))+sin((2*pi*f2*t/fs)); % Sinal com ruído   
 
X=abs(fft(x));  %frequencia do sinal de entrada com transformada de fourier    %sinal ruidoso 

figure(1);
title('Sinal ruidoso');
figure(2);
v=length(x);
plot(X(1:v/2)); 
%plotando a frequencia do sinalde entrada  
title('Frequencia do sinal');   %Filtro passa baixa janela de Hamming  
F_corte=fc*2/fs;
w=F_corte;
n=100;
h=hamming(n+1);
Hamming=fir1(n,w,'low',h); 
[H,w]=freqz(Hamming,1); 
figure(3);
plot((w*(fs/2*pi)),abs(H*9000)); 
title ('Resposta filtro de Hamming' );

fh=filter(Hamming,1,x); figure(4); plot(fh); title('Sinal janela de Hamming filtrado');