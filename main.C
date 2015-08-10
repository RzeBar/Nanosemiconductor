#include <iostream>
#include <vector>
#include "nanoSemiconductor.h"

int main(){
//dx,dy,dz,
//nx,ny,nz,nz1,nz2,iter,itp,
//nx1,nx2,nx3,nx4,nx5,nx6,nx7,nx8,nx9,nx10,nx11,nx12,
//ny1,ny2,ny3,ny4,ny5,ny6,ny7,ny8,ny9,ny10,ny11,ny12,
//v0,v1,v2,v3,v4,v5,v6
nanoSemiconductor c1(	10,10,10,
			50,50,25,10,15,50,100,
			0,20,  30,50,  0,10,  40,50,  0,20,  30,50,  
			0,10,  0,10,  20,30,  20,30,  40,50,  40,50,  
			-350,450,450,300,300,450,450
		   );


c1.simulate();
c1.save("vxy.dat" , "map.dat" , "pot.dat");// rozkład potencjału , mapa elektrod , potencjał w srodku

	return 0;
}


