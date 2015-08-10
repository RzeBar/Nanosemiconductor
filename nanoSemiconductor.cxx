#ifndef NANO_SEMI_H
#define NANO_SEMI_H
#include "nanoSemiconductor.h"

#include <fstream> 
#include <iomanip>

nanoSemiconductor::nanoSemiconductor(double arg_dx ,double arg_dy ,double arg_dz ,
	  int arg_nx ,int arg_ny ,int arg_nz ,int arg_nz1 ,int arg_nz2 ,int arg_iter ,int arg_itp,
	  double arg_nx1,double arg_nx2,double arg_nx3,double arg_nx4,double arg_nx5,double arg_nx6,double arg_nx7,double arg_nx8,double arg_nx9,double arg_nx10,double arg_nx11,double arg_nx12,
	  double arg_ny1,double arg_ny2,double arg_ny3,double arg_ny4,double arg_ny5,double arg_ny6,double arg_ny7,double arg_ny8,double arg_ny9,double arg_ny10,double arg_ny11,double arg_ny12,
	  double arg_v0 , double arg_v1 , double arg_v2 , double arg_v3 , double arg_v4 , double arg_v5 , double arg_v6):
	dx(arg_dx),dy(arg_dy),dz(arg_dz),nx(arg_nx),ny(arg_ny),nz(arg_nz),nz1(arg_nz1),nz2(arg_nz2),
	iter(arg_iter),itp(arg_itp),
	nx1(arg_nx1),nx2(arg_nx2),nx3(arg_nx3),nx4(arg_nx4),nx5(arg_nx5),nx6(arg_nx6),nx7(arg_nx7),nx8(arg_nx8),nx9(arg_nx9),nx10(arg_nx10),nx11(arg_nx11),nx12(arg_nx12),
	ny1(arg_ny1),ny2(arg_ny2),ny3(arg_ny3),ny4(arg_ny4),ny5(arg_ny5),ny6(arg_ny6),ny7(arg_ny7),ny8(arg_ny8),ny9(arg_ny9),ny10(arg_ny10),ny11(arg_ny11),ny12(arg_ny12),
	v0(arg_v0),v1(arg_v1),v2(arg_v2),v3(arg_v3),v4(arg_v4),v5(arg_v5),v6(arg_v6)
	{ 

	idxNum=100;
  // Allocate memory
	vtot = new double**[idxNum];
	vtot1 = new double**[idxNum];
	for (int i = 0; i < idxNum; ++i) {
		vtot[i] = new double*[idxNum];
		vtot1[i] = new double*[idxNum];
		for (int j = 0; j < idxNum; ++j){
			 vtot[i][j] = new double[idxNum];
			 vtot1[i][j] = new double[idxNum];
		}
	}

  // Assign values	
	for( int i=0; i<idxNum ; i++)
	for( int j=0; j<idxNum ; j++)
	for( int k=0; k<idxNum ; k++){
		 vtot[i][j][k]=0;	 
		vtot1[i][j][k]=0; 
	}

	vecPot = new int[iter];



	std::cout<<"nanoSemiconductor has been created"<<std::endl;	


}

	
nanoSemiconductor::~nanoSemiconductor(){
	for (int i = 0; i < idxNum; ++i) {
		for (int j = 0; j < idxNum; ++j){
			delete [] vtot[i][j];
			delete [] vtot1[i][j];
		}
	delete [] vtot[i];
	delete [] vtot1[i];
	}
	delete [] vtot;
	delete [] vtot1;

}

void nanoSemiconductor::simulate(){
	std::cout<<"Simulation started!"<<std::endl;

	for( int it=1; it<iter ; it++){
		Poisson();
		vecPot[it]=vtot[nx/2][ny/2][nz1];
		if(it%5==0)
		std::cout<<std::setprecision(3)<< 1.*it/iter <<std::endl;
	}


}

void nanoSemiconductor::Poisson(){

for( int it=1; it<itp ; it++){

for( int i=1; i<=nx-1 ; i++)
for( int j=1; j<=ny-1 ; j++)
for( int k=1; k<=nz-1 ; k++)
{

 double dd=2./dx/dx+2./dy/dy+2./dz/dz;
 double w=(vtot[i+1][j][k]+vtot[i-1][j][k])/dx/dx+(vtot[i][j+1][k]+vtot[i][j-1][k])/dy/dy+(vtot[i][j][k+1]+vtot[i][j][k-1])/dz/dz;
	vtot1[i][j][k]=w/dd;

//warunki brzegowe na ściankach pudła i w podłożu
 if(i == 1) vtot[0][j][k]=vtot[1][j][k];
 if(j == 1) vtot[i][0][k]=vtot[i][1][k];
 if(i == nx-1) vtot[nx][j][k]=vtot[nx-1][j][k];
 if(j == ny-1) vtot[i][ny][k]=vtot[i][ny-1][k];
 if(k == nz-1) vtot[i][j][nz]=vtot[i][j][nz-1];
 if(k == 1) vtot[i][j][0]=v0 ;
}

//przepisujemy potencjał do poprzedniego pliku
for( int i=1; i<=nx-1 ; i++){
	for( int j=1; j<=ny-1 ; j++){
		for( int k=1; k<=nz-1 ; k++){
			vtot[i][j][k]=vtot1[i][j][k];
		}
	}
}
//narzucamy warunki na elektrodach
 int k=nz2;

	for( int i=nx1; i<=nx2 ; i++){
		for( int j=ny1; j<=ny2 ; j++){
			vtot[i][j][k]=v1;
		}
	}

	for( int i=nx3; i<=nx4 ; i++){
		for( int j=ny3; j<=ny4 ; j++){
			vtot[i][j][k]=v2;
		}
	}

	for( int i=nx5; i<=nx6 ; i++){
		for( int j=ny5; j<=ny6 ; j++){
			vtot[i][j][k]=v3;
		}
	}

	for( int i=nx7; i<=nx8 ; i++){
		for( int j=ny7; j<=ny8 ; j++){
			vtot[i][j][k]=v4;
		}
	}

	for( int i=nx9; i<=nx10 ; i++){
		for( int j=ny9; j<=ny10 ; j++){
			vtot[i][j][k]=v5;
		}
	}

	for( int i=nx11; i<=nx12 ; i++){
		for( int j=ny11; j<=ny12 ; j++){
			vtot[i][j][k]=v6;
		}
	}
}
//wypełnienie narożników
vtot[0][0][nz1]=vtot[1][1][nz1];
vtot[0][ny][nz1]=vtot[1][ny-1][nz1];
vtot[nx][0][nz1]=vtot[nx-1][1][nz1];
vtot[nx][ny][nz1]=vtot[nx-1][ny-1][nz1];


}


void nanoSemiconductor::save(std::string vxyName, std::string mapName, std::string potName){

  std::fstream f1 ("output/"+vxyName,std::fstream::out);
  std::fstream f2 ("output/"+mapName,std::fstream::out);
  std::fstream f3 ("output/"+potName,std::fstream::out);

	double x,y;

	for( int i=0; i <= nx; i++){
		for( int j=0; j <= ny; j++){

			int w=0;

			 if(i >= nx1 && i <= nx2 && j >= ny1 && j <= ny2) w=w+1;
			 if(i >= nx3 && i <= nx4 && j >= ny3 && j <= ny4) w=w+1;
			 if(i >= nx5 && i <= nx6 && j >= ny5 && j <= ny6) w=w+1;
			 if(i >= nx7 && i <= nx8 && j >= ny7 && j <= ny8) w=w+1;
			 if(i >= nx9 && i <= nx10 && j >= ny9 && j <= ny10) w=w+1;
			 if(i >= nx11 && i <= nx12 && j >= ny11 && j <= ny12) w=w+1;
			 x=i*dx;
			 y=j*dy;
			 f1<<x<<" "<<y<<" "<<vtot[i][j][nz1]<<std::endl;
			 f2<<x<<" "<<y<<" "<<w<<std::endl;
		}
			 f1<<std::endl;
			 f2<<std::endl;
	}

	for( int it=1; it<iter ; it++){
		f3<<std::fixed<<it<<" "<<vecPot[it]<<std::endl;
	}

	f1.close();
	f2.close();
	f3.close();

}



#endif

