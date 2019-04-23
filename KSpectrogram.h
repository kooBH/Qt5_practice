#ifndef _H_SPEC_
#define _H_SPEC_

#include "KWidget.h"
#include "KLabel.h"

#include <QImage>              
#include <QPixmap>            
#include <QColor>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
class KSpectrogram : public KWidget{
  private:
    FILE*fp;
    QImage img;
    QPixmap buf;
    KLabel label;
    QVBoxLayout layout;
  public:
    KSpectrogram(const char* file_name):KWidget(),img(2497,257,QImage::Format_RGB16),label(nullptr){
    int max=0,min=100;
       printf("%d%d\n",img.width(),img.height());
       int i,j;
       double t;
       int f;
       int r,g,b;

//257        2497
       //fp = fopen("../input_fft.mat","rb");
       fp = fopen(file_name,"rb");
       //for(i=0;!feof(fp);i++){
       for(i=0;i<2497;i++){
         for(j=0;j<257;j++){
           fread(&t,sizeof(double),1,fp);
           //f = (int)(t*100) + 17;
//           printf("> %lf ",t);
           printf("%lf ",t);
//t*=(double);
t +=4;
t *=0.9;
/* sigmoid t = (0,1)  */
t =  exp(t)/(exp(t)+1);
t *= 250;


  //         printf("%lf ",t);
                     
    //       printf("%lf ",t);
           f = (int )t;
           printf("> %lf | ",t);

           if(f>255 )
             f=255;
           else if(f <-255)
             f =0;
           r = f>128 > 0 ? 2*(f-128):0;
           g = f>127? 255-2*(f-128) : 2*f; 
           b = f < 128 ? 255-2*f:0;
           printf("%d %d %d %d\n",r,g,b,f);
         //  if(f>100)             printf("%d\n",f);
           //img.setPixelColor(i,256-j,QColor(f,f/2,0,255));
           //img.setPixelColor(i,256-j,QColor(f,255-f,128,255));
           img.setPixelColor(i,256-j,QColor(r,g,b,255));
//           printf("%lf %d\n",t,f);
         
           if(f>max)max=f;
           if(f<min)min=f;
           if(feof(fp))
             break;

         }
           if(feof(fp))
             break;
       }
      // img = img.scaledToHeight(514);

       printf("max %d | min %d\n",max,min);
       printf("i %d\n",i);

       fclose(fp);
       buf = QPixmap::fromImage(img);
//label.setPixmap(buf.scaled(label.width(),label.height(),Qt::KeepAspectRatio));
       label.setPixmap(buf);
       layout.addWidget(&label);
       setLayout(&layout);

    }
    ~KSpectrogram(){}


};

#endif


