imagemEntrada = imread('./ImagemTeste.jpg');
% imageinfo('./ImagemTeste.jpg')

L = 2^8;

%imagemEntrada = rgb2gray(imagemEntrada);

for k = 1:size(imagemEntrada,3)
    for l= 1:size(imagemEntrada,1)
        for c= 1:size(imagemEntrada,2)
           imagemSaida1(l,c,k) = L-1-imagemEntrada(l,c,k);
        end
    end
end

subplot(1,2,1);
imshow(imagemEntrada);
subplot(1,2,2);
imshow(imagemSaida1);
