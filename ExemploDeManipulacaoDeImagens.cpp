// **********************************************************************
// PUCRS/FACIN
// Programa de testes para manipulação de Imagens
//
// Marcio Sarroglia Pinho
//
// pinho@pucrs.br
// **********************************************************************

#include <iostream>
#include <cmath>

using namespace std;

#ifdef _MSC_VER

#endif

#ifdef WIN32
#include <windows.h>
#include "gl\glut.h"
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

#include "SOIL/SOIL.h"

#include "ImageClass.h"

ImageClass Image, NewImage, ResetImage, ImageResult;

//const int LIMIAR = 230;
float zoom = 0;
#define LARGURA_JAN 1000
#define ALTURA_JAN 500

// **********************************************************************
//  void Morphology(void) ABERTURA
// **********************************************************************

void Morphology()
{
    cout << "Iniciou Morphologia - Erosao e Dilatacao..." << endl;

    int sizeX = Image.SizeY();
    int sizeY = Image.SizeY();
    int x, y;
    int i;
    int Vetor[9];

    // EROSAO

    for(x=1; x<sizeX-1; x++)
    {
        for(y=1; y<sizeY-1; y++)
        {
            i = Image.GetPointIntensity(x, y);
            if(i == 0)
            {
                if(x > 0 && Image.GetPointIntensity(x-1, y) == 255)
                {
                    NewImage.DrawPixel(x-1,y,0,0,0);
                }
                if(y > 0 && Image.GetPointIntensity(x, y-1) == 255)
                {
                    NewImage.DrawPixel(x,y-1,0,0,0);
                }
                if (x + 1 < sizeX && Image.GetPointIntensity(x+1, y) == 255)
                {
                    NewImage.DrawPixel(x+1,y,0,0,0);
                }
                if (y + 1 < sizeY && Image.GetPointIntensity(x, y+1) == 255)
                {
                    NewImage.DrawPixel(x,y+1,0,0,0);
                }
                NewImage.DrawPixel(x,y,0,0,0);
            }
            else
            {
                NewImage.DrawPixel(x,y,255,255,255);
            }
        }
    }


    NewImage.CopyTo(&Image);

    // DILATACAO


    for(x=1; x<sizeX-1; x++)
    {
        for(y=1; y<sizeY-1; y++)
        {
            i = Image.GetPointIntensity(x, y);
            if(i == 255)
            {
                if(x > 0 && Image.GetPointIntensity(x-1, y) == 0)
                {
                    NewImage.DrawPixel(x-1,y,255,255,255);
                }
                if(y > 0 && Image.GetPointIntensity(x, y-1) == 0)
                {
                    NewImage.DrawPixel(x,y-1,255,255,255);
                }
                if (x + 1 < sizeX && Image.GetPointIntensity(x+1, y) == 0)
                {
                    NewImage.DrawPixel(x+1,y,255,255,255);
                }
                if (y + 1 < sizeY && Image.GetPointIntensity(x, y+1) == 0)
                {
                    NewImage.DrawPixel(x,y+1,255,255,255);
                }

                NewImage.DrawPixel(x,y,255,255,255);
            }
            else
            {
                NewImage.DrawPixel(x,y,0,0,0);
            }
        }
    }

    cout << "Concluiu Morphologia - Erosao e Dilatacao..." << endl;

}
// **********************************************************************
//  void ConvertBlackAndWhite()
// **********************************************************************
void ConvertBlackAndWhite(int limiar)
{
    int first = 255;
    int second = 0;
    unsigned char r,g,b;
    int x,y;
    int i;
    cout << "Iniciou Black & White....";
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            Image.ReadPixel(x,y,r,g,b);

            if (i < limiar)
            {
                NewImage.DrawPixel(x, y,first,first,first);  // exibe um ponto PRETO na imagem
            }
            else NewImage.DrawPixel(x, y, second,second,second); // exibe um ponto VERMELHO na imagem

        }
    }
    cout << "Concluiu Black & White." << endl;
}


// **********************************************************************
//  void ConvertBlackAndWhite()
// **********************************************************************
void Separar(int limiar)
{
    int first = 255;
    int second = 0;
    unsigned char r,g,b;
    int x,y;
    int i;
    cout << "Iniciou Black & White....";
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            Image.ReadPixel(x,y,r,g,b);

            if(i == 0){
                    NewImage.DrawPixel(x, y,255,0,0);  // exibe um ponto PRETO na imagem
            }else{
                if (i < limiar)
                {
                    NewImage.DrawPixel(x, y,first,first,first);  // exibe um ponto PRETO na imagem
                }
                else NewImage.DrawPixel(x, y, second,second,second); // exibe um ponto VERMELHO na imagem
            }
        }
    }
    cout << "Concluiu Black & White." << endl;
}

// **********************************************************************
//  void CopyImageNova()
// **********************************************************************
void CopyImageNovaToImage()
{
    unsigned char r,g,b;
    int x,y;
    int i;
    cout << "Iniciou CopyImageNova....";
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            NewImage.ReadPixel(x,y,r,g,b);
            Image.DrawPixel(x,y,r,g,b);  // copia imagem
        }
    }
    cout << "Concluiu CopyImageNova." << endl;
}

// **********************************************************************
//  void SaveImage()
// **********************************************************************
void SaveImage()
{
    unsigned char r,g,b;
    int x,y;
    int i;
    cout << "Iniciou SaveImage....";
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            Image.ReadPixel(x,y,r,g,b);
            ResetImage.DrawPixel(x,y,r,g,b);  // copia imagem
        }
    }
    cout << "Concluiu SaveImage." << endl;
}


// **********************************************************************
//  void ResetImageNow()
// **********************************************************************
void ResetImageNow()
{
    unsigned char r,g,b;
    int x,y;
    int i;
    cout << "Iniciou SaveImage....";
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            ResetImage.ReadPixel(x,y,r,g,b);
            Image.DrawPixel(x,y,r,g,b);  // copia imagem
        }
    }
    cout << "Concluiu SaveImage." << endl;
}

void CopyOtherSide(){
    unsigned char r,g,b;
    int x,y;
    int i;
    cout << "Iniciou SaveImage....";
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            Image.ReadPixel(x,y,r,g,b);
            NewImage.DrawPixel(x,y,r,g,b);  // copia imagem
        }
    }
    cout << "Concluiu SaveImage." << endl;
}

// **********************************************************************
// void DetectImageBorders()
// **********************************************************************
void DetectImageBorders()
{
    cout << "Iniciou DetectImageBorders...." << endl;

    unsigned char r,g,b;
    int x, y, sum, sumX, sumY;

    // SOBEL

    double vertical[3][3] = {
        1, 0, -1,
        2, 0, -2,
        1, 0, -1
    };

    double horizontal[3][3] = {
        -1, -2, -1,
        0,  0,  0,
        1,  2,  1
    };

    for(x=1; x<Image.SizeX()-1; x++)
    {
        for(y=1; y<Image.SizeY()-1; y++)
        {
            Image.ReadPixel(x, y, r, g, b);

            sumX = 0;
            sumY = 0;

            for(int i = -1; i < 3; i++)
            {
                for(int j = -1; j < 3; j++)
                {
                    sumX = sumX + vertical[j+1][i+1] * Image.GetPointIntensity(x+j,y+i);
                }
            }

            for(int i = -1; i < 3; i++)
            {
                for(int j = -1; j < 3; j++)
                {
                    sumY = sumY + horizontal[j+1][i+1] * Image.GetPointIntensity(x+j,y+i);
                }
            }

            sum = sqrt(pow((double)sumX,2) + pow((double)sumY,2));
            if(sum > 0)
               cout << "TESTE. " << sum << endl;

            if (sum > 192)
                NewImage.DrawPixel(x, y, 255, 255, 255);
            if (sum < 0)
                NewImage.DrawPixel(x, y, 0, 0, 0);
        }
    }


    cout << "Concluiu DetectImageBorders." << endl;

}


// **********************************************************************
// void SegmentacaoDescontinuidades()
// **********************************************************************
void SegmentacaoDescontinuidades()
{
    cout << "Iniciou Segmentacao por Descontinuidades...." << endl;

    int x, y, sum, sumX, sumY;
    double dx, dy;
    int a,b, magnitude = 0;


    for(x=1; x<Image.SizeX()-1; x++){
        for(y=1; y<Image.SizeY()-1; y++){

            dx = (Image.GetPointIntensity(x+1, y)-Image.GetPointIntensity(x-1, y))/2;


            a = Image.GetPointIntensity(x+1, y-1);
            b = Image.GetPointIntensity(x-1, y-1);
            dx += (a-b)/2;

            a = Image.GetPointIntensity(x+1, y+1);
            b = Image.GetPointIntensity(x-1, y+1);
            dx += (a-b)/2;

            dx = dx/3;


            a = Image.GetPointIntensity(x, y+1);
            b = Image.GetPointIntensity(x, y-1);
            dy = (a-b)/2;


            a = Image.GetPointIntensity(x+1, y+1);
            b = Image.GetPointIntensity(x+1, y-1);
            dy += (a-b)/2;

            a = Image.GetPointIntensity(x-1, y+1);
            b = Image.GetPointIntensity(x-1, y-1);
            dy += (a-b)/2;

            dy = dy/3;
            magnitude = 0;
            magnitude = sqrt(pow((double)dx,2) + pow((double)dy,2));
            cout << "magnitude= " << sum << "dx =" << dx << " dy" << dy << endl;
            dx = 0; dy =0;
            NewImage.Clear();
            if (sum > 192)
                NewImage.DrawPixel(x, y, 255, 255, 255);
            if (sum < 0)
                NewImage.DrawPixel(x, y, 0, 0, 0);
        }
    }


    cout << "Concluiu SegmentacaoDescontinuidades." << endl;

}

// **********************************************************************
// void ConvertToGrayscale()
// **********************************************************************
void ConvertToGrayscale()
{
    cout << "Iniciou ConvertToGrayscale..." ;
    int x,y;
    int i;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // Le o TOM DE CINZA DA IMAGEM
            NewImage.DrawPixel(x, y,i,i,i);  // exibe um ponto CINZA na imagem da direita
        }
    }
    cout << "Concluiu ConvertToGrayscale." << endl;
}

// **********************************************************************
// void InvertImage()
// **********************************************************************
void InvertImage()
{
    cout << "Iniciou InvertImage..." << endl;

    unsigned char r,g,b;
    int x,y;
    int i;
    int invert = Image.SizeX();

    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            Image.ReadPixel(x,y,r,g,b);
            NewImage.DrawPixel(invert-x,y,r,g,b);  // copia imagem
        }
    }

    cout << "Concluiu InvertImage." << endl;
}
// **********************************************************************
//  void Smoothing(void)
// **********************************************************************
void Smoothing()
{

    cout << "Iniciou Smoothing..." << endl;

    unsigned char r,g,b;
    int sizeX = Image.SizeY();
    int sizeY = Image.SizeY();
    int x, y;

    double multiplier = 1.0/16.0;

    double filter[3][3] =  {
        1, 2, 1,
        2, 4, 2,
        1, 2, 1,

    };

    for(x=0; x<sizeX; x++)
    {
        for(y=0; y<sizeY; y++)
        {
            double red = 0.0;
            double green = 0.0;
            double blue = 0.0;

            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    int iy = i+y;
                    int jx = j+x;
                    Image.ReadPixel(jx, iy, r, g, b);
                    red = r + red * filter[j+1][i+1] * multiplier;
                    green = g + green  * filter[j+1][i+1] * multiplier;
                    blue = b  + blue * filter[j+1][i+1] * multiplier;
                }
            }

            if(red>255) red=255;
            if(green>255) green=255;
            if(blue>255) blue=255;

            if(red<0) red=0;
            if(green<0) green=0;
            if(blue<0) blue=0;

            NewImage.DrawPixel(x, y, red, green, blue);

        }
    }

    NewImage.CopyTo(&Image);

    cout << "Concluiu Smoothing..." << endl;
}

void OrdenaVetor(int window[])
{
    int temp, i , j;
    for(i = 0; i < 9; i++)
    {
        temp = window[i];
        for(j = i-1; j >= 0 && temp < window[j]; j--)
        {
            window[j+1] = window[j];
        }
        window[j+1] = temp;
    }
}
void MontaVetor(int Px, int Py, int Vetor[9])
{
    int other = 0;
    if(Py > 3 && Py < (Image.SizeY() -3) ){
        Vetor[0] = Image.GetPointIntensity(Px,Py);
        Vetor[1] = (Px > 3) ? Image.GetPointIntensity(Px-1,Py) : other;
        Vetor[2] = (Px > 3) ? Image.GetPointIntensity(Px-1,Py-1) : other;
        Vetor[3] = (Px < (Image.SizeX() - 3)) ? Image.GetPointIntensity(Px+1,Py) : other;
        Vetor[4] = (Px < (Image.SizeX() - 3)) ? Image.GetPointIntensity(Px+1,Py-1): other;
        Vetor[5] = (Px < (Image.SizeX() - 3)) ? Image.GetPointIntensity(Px+1,Py+1): other;
        Vetor[6] = Image.GetPointIntensity(Px,Py-1);
        Vetor[7] = Image.GetPointIntensity(Px,Py+1);
        Vetor[8] = (Px > 3) ? Image.GetPointIntensity(Px-1,Py+1) : other;
        Vetor[9] = (Px < (Image.SizeX() - 3)) ?Image.GetPointIntensity(Px+1,Py-1): other;
    }

}
// **********************************************************************
// void RemoverPreto()
// **********************************************************************
void RemoverPreto(){
    cout << "Iniciou RemoverPreto..." ;
    int x,y;
    int preto = 0;

    int i;

    for(x=0; x<Image.SizeX(); x++){
        for(y=0; y<Image.SizeY(); y++){

            i = NewImage.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            //Image.ReadPixel(x,y,r,g,b);

            if (i == 0){
               Image.DrawPixel(x, y,preto,preto,preto);  // exibe um ponto PRETO na imagem
            }

        }
    }


    cout << "Concluiu RemoverPreto..." << endl;
}

void RemoverImagemCor(int r, int g, int b){
    cout << "Iniciou RemoverPreto..." ;
    int x,y;
    unsigned char rr,rg,rb;
    int preto = 0;

    int i;

    for(x=0; x<Image.SizeX(); x++){
        for(y=0; y<Image.SizeY(); y++){


            NewImage.ReadPixel(x,y,rr,rg,rb);

            if (rr == r && rg == g && rb == b){
               Image.DrawPixel(x, y,r,g,b);  // exibe um ponto PRETO na imagem
            }else{
               Image.DrawPixel(x, y,preto,preto,preto);  // exibe um ponto PRETO na imagem
            }

        }
    }


    cout << "Concluiu RemoverPreto..." << endl;
}

void PreencherRecursivo(int x, int y,int maxX, int maxY, int border){
    int r= 255, g =0, b =0;
    if(NewImage.GetPointIntensity(x, y) > 160  && x > border && x < maxX && y > border && y < maxY){
        NewImage.DrawPixel(x, y, r,g,b);

        PreencherRecursivo(x+1,y, maxX, maxY, border);
        PreencherRecursivo(x+1,y+1, maxX, maxY, border);
        PreencherRecursivo(x+1,y-1, maxX, maxY, border);
        PreencherRecursivo(x,y+1, maxX, maxY, border);
        PreencherRecursivo(x-1,y+1, maxX, maxY, border);
        PreencherRecursivo(x-1,y-1, maxX, maxY, border);
        PreencherRecursivo(x-1,y, maxX, maxY, border);

    }
}

void Preencher(ImageClass imageRef, int intensity){

    cout << "Preencher ..." << endl;
    int step = 0, i = 0, countI = 1, x, y;
    int r= 255, g =0, b =0;
    int border = 50, maxX = imageRef.SizeX() - border, maxY = imageRef.SizeY() - border;

    for(x=border; x<=maxX; x++){
        for(y=border; y<=maxY; y++){
            if(NewImage.GetPointIntensity(x, y) > 160){
                PreencherRecursivo(x,y, maxX, maxY, border);
                return;
            }
        }
    }
}
// **********************************************************************
// void PreenchimentoArea() - passear imagem
// **********************************************************************

int CalcularAreaCirculos(int x, int y, ImageClass imageRef, int circleTimes){
    int acc = 0, step = 0, i = 0, countI = 1;

    int border = 50, maxX = imageRef.SizeX() - border, maxY = imageRef.SizeY() - border;
    if(imageRef.GetPointIntensity(x, y) != 0){

        while(step < circleTimes && x > border && x < maxX && y > border && y < maxY){

                if(imageRef.GetPointIntensity(++x, y) != 0){
                    acc++;
                }

                if(imageRef.GetPointIntensity(x, ++y) != 0){
                    acc++;
                }

            for(i=0;i <= countI;i++){

                    if(imageRef.GetPointIntensity(--x, y) != 0){
                        acc++;
                    }

            }
            for(i=0;i <= countI;i++){


                    if(imageRef.GetPointIntensity(x, --y) != 0){
                        acc++;
                    }

            }
            for(i=0;i <= countI;i++){

                    if(imageRef.GetPointIntensity(++x, y) != 0){
                        acc++;
                    }

            }
            countI++;
            step ++;
        }

    }
    //if(acc > 0){cout << acc << " "; } // mostra somas

    return acc;
}
// **********************************************************************
// void PreencherAreaImagem()
// **********************************************************************
void PreencherAreaImagem(ImageClass imageRef, int sizeCut, int circleTimes){

    int x, y;
    int b = 0; // cor que vai ser pintado

    for(x=0; x<imageRef.SizeX(); x++){
        for(y=0; y<imageRef.SizeY(); y++){
            if (CalcularAreaCirculos(x,y, imageRef, circleTimes) < sizeCut){
               imageRef.DrawPixel(x, y, b, b, b);
            }

        }
    }

}
// **********************************************************************
// void RemoveBorder() -  remove a borda com o tamanho do parametro
// substituindo por preto
// **********************************************************************
void RemoveBorder(ImageClass imageRef, int boaderSize){
     cout << "Iniciou RemoveBoard...";

    int maxBoarderX = imageRef.SizeX() - boaderSize;
    int maxBoarderY = imageRef.SizeY() - boaderSize;
    int x, y;
    int b = 0; // cor que vai ser pintado

    for(x=0; x<imageRef.SizeX(); x++){
        for(y=0; y<imageRef.SizeY(); y++){
            if(x <= boaderSize || x >= maxBoarderX || y <= boaderSize || y >= maxBoarderY){
               imageRef.DrawPixel(x, y, b, b, b);
            }

        }
    }

     cout << "Concluiu RemoveBoard..." << endl;
}
// **********************************************************************
// void Sobel() - Filtro Passa Alta()
// **********************************************************************
void Sobel(){
    cout << "Iniciou Sobel..." << endl;


    cout << "Concluiu Sobel..." << endl;
}
// **********************************************************************
// void Dilatacao()
// **********************************************************************
void Dilatacao(){
    cout << "Iniciou Dilatacao..." << endl;
    int x,y, i;
    int estrutura[9][9];

    int imagemA[Image.SizeX()][Image.SizeY()], imagemB[Image.SizeX()][Image.SizeY()];
    int sizeX = Image.SizeY();
    int sizeY = Image.SizeY();
    int branco = 255;
    int preto = 0;


    for(x=0; x<Image.SizeX(); x++){
        for(y=0; y<Image.SizeY(); y++){
            i = Image.GetPointIntensity(x, y);
        }
    }

    for(x=0; x<sizeX-1; x++)
    {
        for(y=0; y<Image.SizeY()-1; y++)
        {
            i = Image.GetPointIntensity(x, y);
            if(i == 255)
            {
                if(x > 0 && Image.GetPointIntensity(x-1, y) == 0)
                {
                    NewImage.DrawPixel(x-1,y,255,255,255);
                }
                if(y > 0 && Image.GetPointIntensity(x, y-1) == 0)
                {
                    NewImage.DrawPixel(x,y-1,255,255,255);
                }
                if (x + 1 < sizeX && Image.GetPointIntensity(x+1, y) == 0)
                {
                    NewImage.DrawPixel(x+1,y,255,255,255);
                }
                if (y + 1 < sizeY && Image.GetPointIntensity(x, y+1) == 0)
                {
                    NewImage.DrawPixel(x,y+1,255,255,255);
                }

                NewImage.DrawPixel(x,y,255,255,255);
            }
            else
            {
                NewImage.DrawPixel(x,y,0,0,0);
            }
        }
    }


    cout << "Concluiu Dilatacao..." << endl;
}
// **********************************************************************
// void Mediana()
// **********************************************************************
void ZoomMore(){
    cout << "Inicializa ZoomMore em " << zoom << "..." <<  endl;

    NewImage.SetZoomH(zoom);
    NewImage.SetZoomV(zoom);
    NewImage.Display();
    zoom += 10;
    cout << "Concluiu ZoomMore..." << endl;
}
// **********************************************************************
// void Mediana()
// **********************************************************************
void Mediana()
{
    cout << "Iniciou Mediana..." ;

    int x, y, mediana;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            int vetor[9];
            MontaVetor(x,y, vetor); // Coloca em VETOR os valores das intensidades ao redor do ponto x,y.
            OrdenaVetor(vetor);
            mediana = vetor[5];

            NewImage.DrawPixel(x, y,mediana,mediana,mediana);

        }
    }

    cout << "Concluiu Mediana." << endl;

}
// **********************************************************************
//  void CalcularResult(void)
// **********************************************************************
void CalcularResult(){
    cout << "Iniciou CalcularResult..." << endl;
    int falsoPositivo = 0, falsoNegativo = 0, verdadeiroPositivo = 0, totalPixels = 0;
    //teste de tamanho
    if(Image.SizeX() != ImageResult.SizeX() ||
        Image.SizeY() != ImageResult.SizeY()){
        cout << "IMAGENS COM TAMANHO DIFERENTE." << endl;
        return;
    }
    totalPixels = Image.SizeX() * Image.SizeY();
    int preto = 0;
    int x, y, i, r;
    for(x=0; x<Image.SizeX(); x++){
        for(y=0; y<Image.SizeY(); y++){
            i = Image.GetPointIntensity(x,y);
            r = ImageResult.GetPointIntensity(x,y);
            if(i != preto){  // diferente de preto
                if(r != preto) // resultado diferente preto
                    verdadeiroPositivo ++;
                else if(r == preto){
                    falsoPositivo ++;
                }
            }else if (i == preto){
                if (r != preto)
                    falsoNegativo ++;
            }
        }
    }
    cout << "Falso Positivo:" << falsoPositivo << endl;
    cout << "Falso Negativo:" << falsoNegativo << endl;
    cout << "Verdadeiro Positivo:" << verdadeiroPositivo << endl;
    cout << "Total Pixels:" << totalPixels << endl;
    cout << "Concluiu CalcularResult." << endl;
}
// **********************************************************************
//  void init(void)
// **********************************************************************
void init()
{
    int r;
    // Carrega a uma image
    string resultImage = "02_Train_Mask_DataSet_1.png";
    string nome = "02_Train_DataSet.png";
//    string nome = "Ruido2.bmp";

    string path = "images/2Celulas/";
// No Code::Blocks para MacOS eh necessario usar um path absoluto
// string path = "ArquivosCodeBlocks/Imagens/";

    nome =  path + nome;
    cout << "imagem a ser carregada: *" << nome << "*" << endl;
    r = Image.Load(nome.c_str()); // Carrega uma imagem


    if (!r) exit(1); // Erro na carga da imagem
    else cout << ("Imagem carregada!\n");

    // carregar a imagem para comparar resultados
    resultImage = path + resultImage;
    int other;
    other = ImageResult.Load(resultImage.c_str()); // Carrega uma imagem

    if (!other) exit(1); // Erro na carga da imagem
    else cout << ("Imagem de Resultados carregada!\n");

    // Ajusta o tamnho da imagem da direita, para que ela
    // passe a ter o mesmo tamnho da imagem recem carregada
    // Caso precise alterar o tamanho da nova imagem, mude os parâmetros
    // da na chamada abaixo
    NewImage.SetSize(Image.SizeX(), Image.SizeY(), Image.Channels());

    ResetImage.SetSize(Image.SizeX(), Image.SizeY(), Image.Channels());

    cout << "Nova Imagem Criada" << endl;

}
// **********************************************************************
//  void reshape( int w, int h )
//  trata o redimensionamento da janela OpenGL
// **********************************************************************
void reshape( int w, int h )
{

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    gluOrtho2D(0,w,0,h);

    // Set the clipping volume
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
// **********************************************************************
//  void display( void )
// **********************************************************************
void display( void )
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Fundo de tela preto
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

// Ajusta o ZOOM da imagem para que apareca na metade da janela
    float zoomH = (glutGet(GLUT_WINDOW_WIDTH)/2.0)/(double)Image.SizeX();
    float zoomV = (glutGet(GLUT_WINDOW_HEIGHT))/(double)Image.SizeY();
    Image.SetZoomH(zoomH);
    Image.SetZoomV(zoomV);
// posiciona a imagem no canto inferior esquerdo da janela
    Image.SetPos(0, 0);

// posiciona a imagem nova na metada da direita da janela
    NewImage.SetPos(glutGet(GLUT_WINDOW_WIDTH)/2, 0);

// Ajusta o ZOOM da imagem para que apareca na metade da janela
    NewImage.SetZoomH(zoomH);
    NewImage.SetZoomV(zoomV);

// Coloca as imagens na tela
    Image.Display();
    NewImage.Display();

// Mostra a tela OpenGL
    glutSwapBuffers();
}
// **********************************************************************
//  void trabalho - ordem de execucao para o trabalho da disciplina de CG2
// **********************************************************************
void Trabalho(){
       // Mediana();
      //  CopyImageNovaToImage();
       // Mediana();
       // CopyImageNovaToImage();
       // Mediana();
       // CopyImageNovaToImage();
        ConvertBlackAndWhite(230);
        RemoveBorder(NewImage, 70);
        PreencherAreaImagem(NewImage, 10, 2);
        RemoverPreto();
        CalcularResult();

}

void Histogram() {

  cout << "Iniciou Histogram..." << endl;
  int x, y, i, statistics[255], histogram[255];
  for (i = 0; i <= 255; i++) {
    statistics[i] = 0;
  }

  for(y=0; y <Image.SizeY(); y++){
    for (x = 0; x < Image.SizeX(); x++){
        i = Image.GetPointIntensity(x,y); // Le o TOM DE CINZA DA IMAGEM
        statistics[i] += 1;
    }
  }
  NewImage.Clear();
  cout << "Desenhando Histogram..." << endl;
  for (i = 0; i <= 255; i++) {
    int lineHeight = statistics[i] % Image.SizeY();
    //cout << "Desenhando até o pixel "<< lineHeight << endl;
    cout << "pixel " << i << " quantidade " << statistics[i] << endl;
    NewImage.DrawLineV(i, 1, lineHeight, 0, 0, 0);

  }

  cout << "Concluiu Histogram." << endl;
}


// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
// **********************************************************************
void keyboard ( unsigned char key, int x, int y )
{

    switch ( key )
    {
    case 27: // Termina o programa qdo
        NewImage.Delete();
        Image.Delete();
        exit ( 0 );   // a tecla ESC for pressionada
        break;
    case '2':
        Separar(120);
        break;

    case '3':
        Separar(130); // nucleo das celulas
        break;
    case '4':
        Separar(179); //removcao
        break;
    case '5':
        RemoverImagemCor(255,255,255);
        break;
    case '6':
        Preencher(NewImage, 70);
        break;
    case '7':
        Separar(176);
        break;
    case '8':
        Separar(175);
        break;
    case '9':
        Separar(180);
        break;
    case '0':
        Separar(130); // nucleo das celulas
        RemoverImagemCor(255,255,255);
        break;
    case 'g':
        ConvertToGrayscale();
        break;
    case 'b':
        DetectImageBorders();
        break;
    case 'i':
        InvertImage();
        break;
    case 'n':
        Dilatacao();
        break;
     case 'm':
        Mediana();
        break;
    case 'z':
        CopyImageNovaToImage();
        break;
    case 'x':
        ResetImageNow();
        break;
    case 'v':
        CopyOtherSide();
        break;
    case 'c':
        SaveImage();
        break;
    case 'q':
        RemoverPreto();
        break;
    case 'e':
        Trabalho();    // obrigatório para redesenhar a tela
        break;
    case 'o':
        ZoomMore();
        break;
    case 'p':
        PreencherAreaImagem(NewImage, 10, 2);
        break;
    case 'l':
        CalcularResult();
        break;
    case 'h':
        Histogram();
        break;
    case 'y':
        Smoothing();
    case 't':
        SegmentacaoDescontinuidades();
    default:
        break;
    }
    glutPostRedisplay();    // obrigatório para redesenhar a tela
}
// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )
// **********************************************************************
void arrow_keys ( int a_keys, int x, int y )
{
    switch ( a_keys )
    {
    case GLUT_KEY_UP:       // When Up Arrow Is Pressed...
        break;
    case GLUT_KEY_DOWN:     // When Down Arrow Is Pressed...

        break;
    default:
        break;
    }
}

// **********************************************************************
//  void main ( int argc, char** argv )
// **********************************************************************

int main ( int argc, char** argv )
{
    glutInit            ( &argc, argv );

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (10,10);

    // Define o tamanho da janela gráfica do programa
    glutInitWindowSize  ( LARGURA_JAN, ALTURA_JAN);
    glutCreateWindow    ( "Image Loader" );

    init ();

    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc ( arrow_keys );
    //glutIdleFunc ( display );

    glutMainLoop ( );

    return 0;
}


