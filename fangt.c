#include <dos.h>
#include <process.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <bios.h>
#include <fangtu.h>


void selectpage(int page)
{
	union REGS r;
	r.x.ax=0x4f05;
	r.x.bx=0;
	r.x.dx=page;
	int86(0x10,&r,&r);
}

unsigned char set_SVGA_mode(int vmode)
{
	union REGS r;
	r.x.ax=0x4f02;
	r.x.bx=vmode;
	int86(0x10,&r,&r);
	return(r.h.ah);
}

unsigned int get_SVGA_mode()
{
	union REGS r;
	r.x.ax=0x4f03;
	int86(0x10,&r,&r);
	return(r.x.bx);
}

void set_SVGA_palette(unsigned char r[],  unsigned char g[], unsigned char b[])
{
	int  k;
	for (k = 0; k < 256; k++)
	{
		outportb(0x03C8,k);
		outportb(0x03C9,r[k]>>2);
		outportb(0x03C9,g[k]>>2);
		outportb(0x03C9,b[k]>>2);
	}
}
void bmp(int x,int y,unsigned char *p )
{
	BITMAPFILEHEADER    FileHeader;
	BITMAPINFOHEADER    bmiHeader;
	RGBQUAD             bmiColors[256];
	unsigned char       buffer[1024], r[256], g[256], b[256];
	unsigned int    width, height, linebytes;
	long        offset, position;
	char page_new=0,page_old=0;
	int i,j,k,n,savemode;
	FILE *fp;
	strcpy(buffer,p);
	if((fp=fopen(buffer,"rb"))==NULL)
	{
	    printf("Can't open file: %s",buffer);
	    return;
	}
	if (fread((char *)&FileHeader, sizeof(FileHeader), 1, fp) != 1)
	{
		printf("Can't read file header !/n");
		return;
	}
	if (FileHeader.bfType != 0X4D42)
	{
		fprintf(stderr, "Not a BMP file !/n");
		return;
	}
	if (fread((char *)&bmiHeader, sizeof(bmiHeader), 1, fp) != 1) 
	{
		fprintf(stderr, "Can't read bmiHeader !/n");
		return;
	}
	if (bmiHeader.biBitCount > 8) 
	{
		fprintf(stderr, "Can not display ture color image !/n");
		return;
	}
	if (bmiHeader.biCompression != 0) 
	{
		fprintf(stderr, "Not non-compressed image !/n");
		return;
	}
	width = (unsigned int)bmiHeader.biWidth;
	height = (unsigned int)bmiHeader.biHeight;
	linebytes = ((width*(long)bmiHeader.biBitCount+31)/32)*4;
	if (fread((char *)&bmiColors[0], 4, 256, fp) != 256)
	{
		fprintf(stderr, "Can't get palette !/n");
		return;
	}
	 //savemode=get_SVGA_mode();
   //	 set_SVGA_mode(0x101);
	COLS=640;ROWS=480;
	for (i = 0; i < 256; i++)
	{
		r[i] = bmiColors[i].rgbRed;
		g[i] = bmiColors[i].rgbGreen;
		b[i] = bmiColors[i].rgbBlue;
	}
	set_SVGA_palette(r, g, b);
	offset = FileHeader.bfOffBits;
	fseek(fp, offset, SEEK_SET);
	for(j=height-1;j>=0;j--) 
	{
	    fread(buffer,linebytes,1,fp);
	    for(i=0,n=0;i<width;i++,n++) 
		{
		    position=(j+y)*(long)COLS+x+i;
		    page_new=position/65536l;
		    if(page_new!=page_old)
		    {
			    selectpage(page_new);
			    page_old=page_new;
		    }
		    pokeb(0xa000,position%65536l,buffer[n]);
	    }
	}
	fclose(fp);
}




