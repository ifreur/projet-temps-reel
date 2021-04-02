#include <wand/MagickWand.h>
#include "../ordo.h"

int main(int argc, char *argv[]){

    int tlen;
    Process* myprocess;
    read_file("input",&myprocess,&tlen);
    for(int j = 0 ; j < tlen ; j++){
        printf("%d %d %d\n",myprocess[j].C,myprocess[j].D,myprocess[j].T );
    }


    int nb_process = tlen;
    int time = atoi(argv[1]);
    int *tab;
   // tab = fp_compute(myprocess,tlen,time);
    tab = edf_compute(myprocess,tlen,time);



    MagickWandGenesis();
    MagickWand *test = NewMagickWand();
    
    PixelWand *c_wand = NULL;
    c_wand = NewPixelWand();
	PixelSetColor(c_wand,"white");

    DrawingWand *d_wand = NULL;
	d_wand = NewDrawingWand();

    DrawingWand *text_wand = NULL;
	text_wand = NewDrawingWand();
    DrawSetFontSize(text_wand,60);
    char stringtmp[2];

    MagickNewImage(test,400 + (100 * time) ,300 + (nb_process * 400),c_wand);

    int radius = 100;

PushDrawingWand(d_wand);
	PixelSetColor(c_wand,"rgb(18,189,231)");
	DrawSetStrokeColor(d_wand,c_wand);
	DrawSetStrokeWidth(d_wand,3);

    double  i = 20;
    DrawSetStrokeDashArray(d_wand,1,&i);

    for(int j = 0 ; j < (nb_process*4) + 3 ; j++)
        DrawLine(d_wand,0,j*100,400 + (100 * time),j*100);

    for(int j = 0 ; j < time + 4 ; j++)
        DrawLine(d_wand,j*100,0,j*100,300 + (nb_process * 400));

PopDrawingWand(d_wand);

PushDrawingWand(d_wand);
	PixelSetColor(c_wand,"rgb(0,0,1)");
	DrawSetStrokeColor(d_wand,c_wand);
	DrawSetStrokeWidth(d_wand,4);
    for(int j = 1 ; j < nb_process + 1 ; j++)
        DrawLine(d_wand,100,j*400,300 + (100 * time),j*400);
PopDrawingWand(d_wand);

PushDrawingWand(d_wand);

    int current = tab[0];
    int inarow = 0;
    PixelSetColor(c_wand,"black");
    DrawSetStrokeColor(d_wand,c_wand);
	DrawSetStrokeWidth(d_wand,4);
	DrawSetStrokeAntialias(d_wand,1);
    PixelSetColor(c_wand,"yellow");
	//DrawSetStrokeOpacity(d_wand,1);
	DrawSetFillColor(d_wand,c_wand);


    for(int j = 0; j < time+1; j++){
        if((current != tab[j]) || (j == time) ){
            if(current != 0){
                DrawRectangle(d_wand,100*j+200,current*400-150,100*(j-inarow)+200,current*400);
                sprintf(stringtmp,"%d",j);
                DrawAnnotation(text_wand,100*(j) + 188,current*400 + 70,stringtmp);
                sprintf(stringtmp,"%d",j-inarow);
                DrawAnnotation(text_wand,100*(j-inarow) + 188,current*400 + 70,stringtmp);
            }
            current = tab[j];
            inarow = 1;
        }
        else
            inarow ++;
    }

PopDrawingWand(d_wand);

PushDrawingWand(d_wand);
	PixelSetColor(c_wand,"rgb(254,0,0)");
	DrawSetStrokeColor(d_wand,c_wand);
	DrawSetStrokeWidth(d_wand,4);
    for(int j = 1 ; j < tlen + 1 ; j++){
        int t_tmp = myprocess[j-1].D;
        while (t_tmp <= time)
        {
            DrawLine(d_wand,100*(t_tmp) +202,j*400-200,100*(t_tmp) +202,j*400);
            sprintf(stringtmp,"%d",t_tmp);
            DrawAnnotation(text_wand,100*(t_tmp) + 188,j*400 + 70,stringtmp);
            t_tmp += myprocess[j-1].T;
        }
        
    }
PopDrawingWand(d_wand);


PushDrawingWand(d_wand);
	PixelSetColor(c_wand,"rgb(9,155,9)");
	DrawSetStrokeColor(d_wand,c_wand);
	DrawSetStrokeWidth(d_wand,6);
    for(int j = 1 ; j < tlen + 1 ; j++){
        int t_tmp = 0;
        while (t_tmp < time)
        {
            DrawLine(d_wand,100*(t_tmp) +196,j*400-200,100*(t_tmp) + 196,j*400);
            sprintf(stringtmp,"%d",t_tmp);
            DrawAnnotation(text_wand,100*(t_tmp) + 188,j*400 + 70,stringtmp);
            t_tmp += myprocess[j-1].T;
        }
    }
PopDrawingWand(d_wand);

	MagickDrawImage(test,d_wand);

    MagickDrawImage(test,text_wand);

    MagickWriteImage(test, "diagramme.bmp");
    DestroyMagickWand(test);
    MagickWandTerminus();

    free(tab);
    return 0;
}