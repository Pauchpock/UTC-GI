% TP 1

I = imread('https://www.hds.utc.fr/~xuphilip/dokuwiki/_media/en/citroen.jpg');
I = im2double(I);
IR = I(:,:,1); % Composante rouge
IG = I(:,:,2); % Composante verte
IB = I(:,:,3); % Composante bleu
%imshow(I);

%figure(1);
%subplot(2,2,1); imshow(I);
%subplot(2,2,2); imshow(IR); title('Rouge');
%subplot(2,2,3); imshow(IG); title('Vert');
%subplot(2,2,4); imshow(IB); title('Bleu');

maskR = IR > 0.0 & IR < 0.5;
maskG = IG > 0.0 & IG < 1.0;
maskB = IB > 0.0 & IB < 0.2;
mask = maskR&maskG&maskB;
%figure(2);
%subplot(2,2,1); imshow(I);
%subplot(2,2,2); imshow(maskB);
%subplot(2,2,3); imshow(I.*repmat(maskB,[1,1,3]));
%subplot(2,2,4); imshow(I.*repmat(mask ,[1,1,3]));

coeff = [1, 0, 0]; % Coefficients de couleur [R,G,B]
IGr = rgb2gray(I);
IR2 = IR; IG2 = IG; IB2 = IB;
%IR2(mask)=coeff(1)*IGr(mask)/max(1,coeff(1)*max(IGr(mask)));
IG2(mask)=coeff(2)*IGr(mask)/max(1,coeff(2)*max(IGr(mask)));
%IB2(mask)=coeff(3)*IGr(mask)/max(1,coeff(3)*max(IGr(mask)));
%figure(3);
%subplot(2,1,1); imshow(mask);
%subplot(2,1,2); imshow(cat(3,IR2,IG2,IB2));

% TP 2
I = imread('cameraman.tif');
scale = 0.25;
Ismall = imresize(I,scale,'bilinear'); % 4 fois plus petit
Ibig = imresize(Ismall,1/scale,'bilinear'); % 4 fois plus gd que Ismall
%'nearest', 'bilinear', 'bicubic'
figure(1);
subplot(3,1,1); imshow(I);
subplot(3,1,2); imshow(Ismall);
subplot(3,1,3); imshow(Ibig);