#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.c>

#define VALINI        2
#define DIMENSION    10

#define PC           'P'
#define PLAYER       'L'
#define BOOM         'X'
#define FALLASTE     'O'
#define FALLOPROPIO  'Z'

#define CT       BLUE
#define CF       LIGHTGRAY

#define ESC        27
#define ENTER      13
#define ESPACIO    32

#define ARRIBA     72
#define ABAJO      80
#define DERECHA    77
#define IZQUIERDA  75
#define S          83
#define N          78


int barcos = 0;
int barcosene = 0;
int fasejuego = 0;
int posxcuad = 0;
int posycuad = 0;
int warningplayer = 0;
int warningpc = 0;

/*
   Función: initcuadro
   Argumentos: int cuadro, Matriz a imprimir.
               int cuadro2, matriz a pasar cambios.
               int dim, Cantidad de filas de la matriz y columnas de la matriz.
               int valini valor inicial de la matriz
   Objetivo: inicializar la matriz 'cuadro' que contiene 'DIMENSION' filas y
            'DIMENSION' columnas.
   Retorno: Ninguno.
*/

void initcuadro(int cuadro[][DIMENSION],int dim,int valini)
{
   int indfil, indcol;

   for ( indfil = 0; indfil < dim; indfil ++ )
   {
      for ( indcol = 0; indcol < dim; indcol ++ )
      {
         cuadro[indfil][indcol] = VALINI;
      }
   }
   cuadro[0][0] = 0;
}

/*
   Función: movimiento
   Argumentos: int cuadro, Matriz a imprimir.
               int cuadro2, matriz a cambiar los valores.
               int dim, Cantidad de filas de la matriz y columnas de la matriz.
               int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: Declara los valores del teclado, permitiendote manejar la matriz a tu gusto, tambien contiene
             varias restricciones.
   Retorno: Ninguno.
*/
void movimientos(int cuadro[][DIMENSION], int cuadro2[][DIMENSION], int dim, int posx, int posy)
{
   int tecla;
   int temp;
   _setcursortype(0);
   do{
      showcuadroxy(cuadro, dim, posx, posy, posycuad, posxcuad);
      do{
         tecla = getch();
      }while (tecla != ESC && tecla != ARRIBA && tecla != ABAJO
              && tecla != DERECHA && tecla != IZQUIERDA && tecla != ENTER && tecla != ESPACIO);

      if ( tecla == ARRIBA )
      {
         if ( posycuad > 0 && cuadro[posycuad-1][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PLAYER
             && cuadro[posycuad-1][posxcuad] != PC && cuadro[posycuad][posxcuad] != PC
             && cuadro[posycuad-1][posxcuad] != BOOM && cuadro[posycuad][posxcuad] != BOOM
             && cuadro[posycuad-1][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLASTE
             && cuadro[posycuad-1][posxcuad] != FALLOPROPIO && cuadro[posycuad][posxcuad] != FALLOPROPIO)
         {
            temp = cuadro[posycuad-1][posxcuad];
            cuadro[posycuad-1][posxcuad] = cuadro[posycuad][posxcuad];
            cuadro[posycuad][posxcuad] = temp;
            posycuad--;
         }
         else if ( posycuad > 0 && (cuadro[posycuad-1][posxcuad] == PLAYER || cuadro[posycuad-1][posxcuad] == PC
                                    || cuadro[posycuad-1][posxcuad] == BOOM || cuadro[posycuad-1][posxcuad] == FALLASTE
                                    || cuadro[posycuad-1][posxcuad] == FALLOPROPIO))
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PC && cuadro[posycuad][posxcuad] != BOOM
                && cuadro[posycuad][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLOPROPIO);
            {
               cuadro[posycuad][posxcuad] = VALINI;
            }
            posycuad--;
         }
         else if ( posycuad > 0 && cuadro[posycuad-1][posxcuad] == VALINI )
         {
            cuadro[posycuad-1][posxcuad] = 0;
            posycuad--;
         }
         else if ( posycuad == 0 )
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PC && cuadro[posycuad][posxcuad] != BOOM
                  && cuadro[posycuad][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLOPROPIO )
                     cuadro[posycuad][posxcuad] = VALINI;
            if ( cuadro[dim-1][posxcuad] != PLAYER && cuadro[dim-1][posxcuad] != PC && cuadro[dim-1][posxcuad] != BOOM
                  && cuadro[dim-1][posxcuad] != FALLASTE && cuadro[dim-1][posxcuad] != FALLOPROPIO )
                     cuadro[dim-1][posxcuad] = 0;
            posycuad = dim-1;
         }
      }

      if ( tecla == ABAJO )
      {
         if ( posycuad < dim-1 && cuadro[posycuad+1][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PLAYER
             && cuadro[posycuad+1][posxcuad] != PC && cuadro[posycuad][posxcuad] != PC
             && cuadro[posycuad+1][posxcuad] != BOOM && cuadro[posycuad][posxcuad] != BOOM
             && cuadro[posycuad+1][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLASTE
             && cuadro[posycuad+1][posxcuad] != FALLOPROPIO && cuadro[posycuad][posxcuad] != FALLOPROPIO)
         {
            temp = cuadro[posycuad+1][posxcuad];
            cuadro[posycuad+1][posxcuad] = cuadro[posycuad][posxcuad];
            cuadro[posycuad][posxcuad] = temp;
            posycuad++;
         }
         else if ( posycuad < dim-1 && (cuadro[posycuad+1][posxcuad] == PLAYER || cuadro[posycuad+1][posxcuad] == PC
                                        || cuadro[posycuad+1][posxcuad] == BOOM || cuadro[posycuad+1][posxcuad] == FALLASTE
                                        || cuadro[posycuad+1][posxcuad] == FALLOPROPIO) )
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PC && cuadro[posycuad][posxcuad] != BOOM
                && cuadro[posycuad][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLOPROPIO )
               cuadro[posycuad][posxcuad] = VALINI;
            posycuad++;
         }
         else if ( posycuad < dim-1 && cuadro[posycuad+1][posxcuad] == VALINI)
         {
            cuadro[posycuad+1][posxcuad] = 0;
            posycuad++;
         }
         else if ( posycuad == dim-1 )
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PC && cuadro[posycuad][posxcuad] != BOOM
                && cuadro[posycuad][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLOPROPIO )
               cuadro[posycuad][posxcuad] = VALINI;
            if ( cuadro[0][posxcuad] != PLAYER && cuadro[0][posxcuad] != PC && cuadro[0][posxcuad] != BOOM
                && cuadro[0][posxcuad] != FALLASTE && cuadro[0][posxcuad] != FALLOPROPIO )
               cuadro[0][posxcuad] = 0;
            posycuad = 0;
         }
      }

      if ( tecla == IZQUIERDA )
      {
         if ( posxcuad > 0 && cuadro[posycuad][posxcuad-1] != PLAYER && cuadro[posycuad][posxcuad] != PLAYER
             && cuadro[posycuad][posxcuad -1] != PC && cuadro[posycuad][posxcuad] != PC
             && cuadro[posycuad][posxcuad -1] != BOOM && cuadro[posycuad][posxcuad] != BOOM
             && cuadro[posycuad][posxcuad -1] != FALLASTE && cuadro[posycuad][posxcuad] != FALLASTE
             && cuadro[posycuad][posxcuad -1] != FALLOPROPIO && cuadro[posycuad][posxcuad] != FALLOPROPIO )
         {
            temp = cuadro[posycuad][posxcuad-1];
            cuadro[posycuad][posxcuad-1] = cuadro[posycuad][posxcuad];
            cuadro[posycuad][posxcuad] = temp;
            posxcuad--;
         }
         else if (  posxcuad > 0 && (cuadro[posycuad][posxcuad-1] == PLAYER || cuadro[posycuad][posxcuad-1] == PC
                                     || cuadro[posycuad][posxcuad-1] == BOOM || cuadro[posycuad][posxcuad-1] == FALLASTE
                                     || cuadro[posycuad][posxcuad-1] == FALLOPROPIO) )
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PC && cuadro[posycuad][posxcuad] != BOOM
                && cuadro[posycuad][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLOPROPIO )
               cuadro[posycuad][posxcuad] = VALINI;
            posxcuad--;
         }
         else if ( posxcuad > 0 && cuadro[posycuad][posxcuad-1] == VALINI )
         {
            cuadro[posycuad][posxcuad-1] = 0;
            posxcuad--;
         }
         else if ( posxcuad == 0 )
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PC && cuadro[posycuad][posxcuad] != BOOM
                && cuadro[posycuad][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLOPROPIO )
               cuadro[posycuad][posxcuad] = VALINI;
            if ( cuadro[posycuad][dim-1] != PLAYER && cuadro[posycuad][dim-1] != PC && cuadro[posycuad][dim-1] != BOOM
                && cuadro[posycuad][dim-1] != FALLASTE && cuadro[posycuad][dim-1] != FALLOPROPIO )
               cuadro[posycuad][dim-1] = 0;
            posxcuad = dim-1;
         }
      }

      if ( tecla == DERECHA )
      {
         if ( posxcuad < dim-1 && cuadro[posycuad][posxcuad+1] != PLAYER && cuadro[posycuad][posxcuad] != PLAYER
             && cuadro[posycuad][posxcuad+1] != PC && cuadro[posycuad][posxcuad] != PC
             && cuadro[posycuad][posxcuad+1] != BOOM && cuadro[posycuad][posxcuad] != BOOM
             && cuadro[posycuad][posxcuad+1] != FALLASTE && cuadro[posycuad][posxcuad] != FALLASTE
             && cuadro[posycuad][posxcuad+1] != FALLOPROPIO && cuadro[posycuad][posxcuad] != FALLOPROPIO )
         {
            temp = cuadro[posycuad][posxcuad+1];
            cuadro[posycuad][posxcuad+1] = cuadro[posycuad][posxcuad];
            cuadro[posycuad][posxcuad] = temp;
            posxcuad++;
         }
         else if ( posxcuad < dim-1 && (cuadro[posycuad][posxcuad+1] == PLAYER || cuadro[posycuad][posxcuad+1] == PC
                                        || cuadro[posycuad][posxcuad+1] == BOOM || cuadro[posycuad][posxcuad+1] == FALLASTE
                                        || cuadro[posycuad][posxcuad+1] == FALLOPROPIO))
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PC && cuadro[posycuad][posxcuad] != BOOM
                && cuadro[posycuad][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLOPROPIO )
               cuadro[posycuad][posxcuad] = VALINI;
            posxcuad++;
         }
         else if ( posxcuad < dim-1 && cuadro[posycuad][posxcuad+1] == VALINI )
         {
            cuadro[posycuad][posxcuad+1] = 0;
            posxcuad++;
         }
         else if ( posxcuad == dim-1 )
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && cuadro[posycuad][posxcuad] != PC && cuadro[posycuad][posxcuad] != BOOM
                && cuadro[posycuad][posxcuad] != FALLASTE && cuadro[posycuad][posxcuad] != FALLOPROPIO )
               cuadro[posycuad][posxcuad] = VALINI;
            if ( cuadro[posycuad][0] != PLAYER && cuadro[posycuad][0] != PC && cuadro[posycuad][0] != BOOM && cuadro[posycuad][0] != FALLASTE
                && cuadro[posycuad][0] != FALLOPROPIO )
               cuadro[posycuad][0] = 0;
            posxcuad = 0;
         }
      }

      if ( tecla == ENTER )
      {
         if (fasejuego == 0)
         {
            if ( cuadro[posycuad][posxcuad] != PLAYER && barcos < 5 )
               agregarbarcos(cuadro, posxcuad, posycuad);
            else if ( cuadro[posycuad][posxcuad] == PLAYER )
               quitarbarcos(cuadro, posxcuad, posycuad);
         }

         if (fasejuego == 2 && (cuadro[posycuad][posxcuad] == PLAYER) )
         {

            bombearbarcos(cuadro, cuadro2,  posxcuad, posycuad);
         }
         else if (fasejuego == 2 && cuadro[posycuad][posxcuad] == PC)
         {
            bombearbarcos(cuadro,cuadro2,posxcuad,posycuad);
         }
         else if (fasejuego == 2 && cuadro[posycuad][posxcuad] == VALINI)
         {
            bombearbarcos(cuadro,cuadro2,posxcuad,posycuad);
         }
      }

      if ( tecla == ESC && fasejuego != 1 && fasejuego != 2 )
      {
         confirmaciondebarcos(cuadro, cuadro2, posx, posy, barcos);
      }
      aviso(posx, posy);
   }while (tecla != ESPACIO && (barcos != 0 && barcosene != 0 || fasejuego != 2) );
}

/*
   Función: showcuadroxy
   Argumentos: int cuadro, Matriz a imprimir.
               int cuadro2, matriz a transferir valores
               int dim, Cantidad de filas de la matriz y columnas de la matriz.
               int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: Imprimir la matriz 'cuadro' que contiene 'DIMENSION' filas y
            'DIMENSION' columnas.
   Retorno: Ninguno.
*/

void showcuadroxy(int cuadro[][DIMENSION], int dim, int posx, int posy, int posycuad, int posxcuad)
{
   int indfil, indcol, esp = ((int)log10(DIMENSION*DIMENSION)+1);

   gotoxy(posx-6, posy-3);
   printf(">>>>>>>> Bienvenido al Battleship <<<<<<<<");

   for ( indfil = 0; indfil < dim; indfil ++ )
   {
      for ( indcol = 0; indcol < dim; indcol ++ )
      {
         setcolor(CT,CF);

         if(cuadro[indfil][indcol] == 0)
            setcolor(CF,CF);

         if ( cuadro[indfil][indcol] == VALINI )
            setcolor(CT,CT);

         if (fasejuego)
            {
               if( cuadro[indfil][indcol] == PLAYER )
                  if (cuadro[posycuad][posxcuad] == cuadro[indfil][indcol])
                     setcolor(CF,CF);
                  else
                     setcolor(CT,CT);
            }

         if( cuadro[indfil][indcol] == PC )
            setcolor(CT,CF);

         if( cuadro[indfil][indcol] == BOOM )
            setcolor(RED,RED);

         if( cuadro[indfil][indcol] == FALLOPROPIO )
            setcolor(BLUE,BLUE);

         if( cuadro[indfil][indcol] == FALLASTE )
            setcolor(GREEN,GREEN);

         gotoxy(posx+indcol * esp,posy+indfil);
         printf("%*c",esp,cuadro[indfil][indcol]);
      }
      colordefault();
      gotoxy(posx-6,posy+15);
      printf("Tus Barcos: %d | Barcos de la computadora: %d\n", barcos, barcosene);
      warnings(posx, posy);
   }
   return;
}

/*
   Función: setcolor
   Argumentos: ct = color de texto
               cf = color de fondo
   Objetivo: cambiar el color de la consola
   Retorno: Ninguno.
*/

void setcolor(int ct, int cf)
{
   textcolor(ct);
   textbackground(cf);
}

/*
   Función: colordefault
   Objetivo: volver al color normal de la consola.
   Retorno: Ninguno.
*/

void colordefault()
{
   textcolor(LIGHTGRAY);
   textbackground(BLACK);
}

/*
  Función: bombearbarcos
   Argumentos: int cuadro, Matriz a imprimir.
               int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: simula cuando bombardeas un barco tuyo, un enemigo y cuando fallas
   Retorno: Ninguno.
*/

void bombearbarcos(int cuadro[][DIMENSION], int cuadro2[][DIMENSION], int posxcuad, int posycuad)
{
   if (cuadro2[posycuad][posxcuad] == PLAYER)
   {
      cuadro[posycuad][posxcuad] = FALLOPROPIO;
      warningplayer = 1;
      barcos--;
   }
   if (cuadro2[posycuad][posxcuad] == PC)
   {
      cuadro[posycuad][posxcuad] = BOOM;
      warningplayer = 2;
      barcosene--;
   }
   if (cuadro[posycuad][posxcuad] == 0)
   {
      cuadro[posycuad][posxcuad] = FALLASTE;
      warningplayer = 3;
   }
   bombearbarcospc(cuadro, cuadro2, cuadro2);
}

/*
   Función: generaraleatorios
   Argumentos: no contiene
   Objetivo: generar numeros aleatorios
   Retorno: rand.
*/
int generarnumerosaleatorios()
{
   return rand() % (9 - 0 + 1) + 0;
}
/*
   Función: bombearbarcospc
   Argumentos: int cuadro, Matriz a imprimir.
               int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: simula cuando la pc bombardea un barco tuyo, de la misma pc o falla de manera randomizada
   Retorno: Ninguno.
*/
void bombearbarcospc(int cuadro[][DIMENSION], int cuadro2[][DIMENSION], int matrizpc[][DIMENSION] )
{
   int indfil, indcol;
   do{
      indfil = generarnumerosaleatorios;
      indcol = generarnumerosaleatorios;
   }while(cuadro2[indfil][indcol] == FALLASTE || matrizpc[indfil][indcol] == FALLASTE || cuadro2[indfil][indcol] == FALLOPROPIO);

   if (cuadro2[indfil][indcol] == PLAYER)
   {
      cuadro[indfil][indcol] = BOOM;
      warningpc = 4;
      barcos--;
   }
   else if (cuadro2[indfil][indcol] == PC)
   {
      cuadro[indfil][indcol] = FALLOPROPIO;
      warningpc = 5;
      barcosene--;
   }
   else if (matrizpc[indfil][indcol] == VALINI)
   {
      matrizpc[indfil][indcol] = FALLASTE;
      warningpc = 6;
   }
   delay(500);
}

/*
   Función: agregarbarcos
   Argumentos: int cuadro, Matriz a imprimir.
               int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: agrega los barcos en forma de caracter en la posicion que señales con las flechas en X e Y
   Retorno: Ninguno.
*/

void agregarbarcos(int cuadro[][DIMENSION], int posxcuad, int posycuad)
{
   cuadro[posycuad][posxcuad] = PLAYER;
   barcos++;
}

/*
   Función: quitarbarcos
   Argumentos: int cuadro, Matriz a imprimir.
               int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: quita los barcos en la posicion que señales con las flechas en X e Y
   Retorno: Ninguno.
*/

void quitarbarcos(int cuadro[][DIMENSION], int posxcuad, int posycuad)
{
   cuadro[posycuad][posxcuad] = 0;
   barcos--;
}

/*
   Función: confirmposicion
      Argumentos: mat y mat2 = se usan para ejecutar barcoscomp
                  posx = se usa para dirigir la posicion del cursor
                  posy = se usa para dirigir la posicion del cursor
                  barcos = se usa para limitar la funcion para que se ejecute barcoscomp cuando sea 5
   Objetivo: que reciba una entrada de numeros y con
   Retorno: Ninguno.
*/

void confirmaciondebarcos (int cuadro[][DIMENSION], int cuadro2[][DIMENSION], int posx, int posy, int barcos)
{
   int tecla;
   if ( barcos == 5 )
   {
      gotoxy(posx-12,posy+12);
      printf("                                                         ");
      gotoxy(posx-9,posy+12);
      printf("> %cQuieres poner tus barcos en estas coordenadas?", 168);
      gotoxy(posx+3,posy+13);
      printf(" -->[S]<-- = SI  /  -->[N]<-- = NO");

      do{
         tecla = getch();
      }while (tecla != S && tecla != N);

         gotoxy(posx-12,posy+12);
         printf("                                                         ");
         gotoxy(posx,posy+13);
         printf("                                    ");
      if ( tecla == S )
      {
         fasejuego = 1;
         generarbarcospc(cuadro, cuadro2,500, barcos, posx, posy);
      }
   }
   else if ( barcos < 5 )
   {
      gotoxy(posx-20, posy+12);
      printf("*:     Primero debes posicionar todos los barcos para confirmar     :*");
   }
}
/*
   Función: generarbarcospc
   Argumentos: int cuadro, Matriz a imprimir.
               int cuadro2, matriz a transferir los valores.
               int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: agrega los barcos enemigos en posiciones randomizadas
   Retorno: Ninguno.
*/

void generarbarcospc(int cuadro[][DIMENSION],int cuadro2[][DIMENSION], int milisegundos, int posx, int posy)
{
   int indfil, indcol;
   while (barcosene < 5)
   {
      indfil = generarnumerosaleatorios();
      indcol = generarnumerosaleatorios();
      gotoxy(posx+35,posy-15);
      if ( cuadro[indfil][indcol] != PLAYER && cuadro[indfil][indcol] != PC && fasejuego == 1)
      {
         cuadro[indfil][indcol] = PC;
         delay(milisegundos);
         barcosene++;

         printf("*: Colocando barco #%d de la pc. :*",  barcosene);

      }
   }
   gotoxy(posx+35,posy-15);
   printf("                                       ");
   gotoxy(posx+25,posy-20);
   printf("*:       %cLa batalla naval ha comenzado!            :*", 173);

   cambiodematriz(cuadro,cuadro2);
   initcuadro(cuadro, DIMENSION, VALINI);
   posxcuad = 0;
   posycuad = 0;
   fasejuego = 2;
}

/*
   Función: delay
   Argumentos: milisegundos = numero de milisegundos
   Objetivo: recibir un argumento de milisegundos y que haga que el programa se pause por ese tiempo.
   Retorno: Ninguno.
*/
void delay(int milisegundos)
{
      clock_t tiempo = clock();
      while (clock() < tiempo + milisegundos);
}
/*
   Función: warnings
   Argumentos: int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: registrar los diferentes avisos y imprimirlos dependiendo de la condicion que se cumpla
   Retorno: Ninguno.
*/
void warnings(int posx, int posy)
{
      if (warningplayer == 1)
      {
         gotoxy(posx-5,posy+12);
         printf("*: hundiste tu propio barco :*");
      }
      if (warningplayer == 2)
      {
         gotoxy(posx-5,posy+12);
         printf("*:     %cBoom! %cHas hundido el barco enemigo!     :*", 173, 173);
      }
      if (warningplayer == 3)
      {
         gotoxy(posx-5,posy+12);
         printf("*:          %cFallaste!          :*", 173);
      }

      if (warningpc == 4)
      {
         gotoxy(posx-5,posy+17);
         printf(">     %cLa pc hundio un barco aliado!   ", 173);
      }
      if (warningpc == 5)
      {
         gotoxy(posx-5,posy+17);
         printf(">     %cLa pc hundio uno de sus barcos!     ", 173);
      }
      if (warningpc == 6)
      {
         gotoxy(posx-5,posy+17);
         printf(">          %cLa pc fallo!               ", 173);
      }
}
/*
   Función: aviso
   Argumentos: int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: avisarte dependiendo de que condicion se cumpla si ganaste o perdiste
   Retorno: Ninguno.
*/
void aviso(int posx, int posy)
{
   if (barcosene == 0 && fasejuego == 2 )
      {
         gotoxy(posx-5,posy+12);
         printf("                                               ");
         gotoxy(posx-5,posy+17);
         printf(">          %cGANASTE!             \n\n", 173);
      }
   if (barcos == 0 && fasejuego == 2 )
   {
      gotoxy(posx-5,posy+17);
      printf(">          %cPERDISTE!               \n\n", 173);
   }
}
/*
   Función: cambiodematriz
   Argumentos: int cuadro, matriz a trabajar.
               int posx coordenadas en x
               int posy coordenadas en y
   Objetivo: hacer un cambio de matriz para transferir los valores de una matriz a otra y poder asi reflejar y
   tambien esconder los barcos de ambos bandos
   Retorno: Ninguno.
*/
void cambiodematriz(int cuadro[][DIMENSION], int cuadro2[][DIMENSION])
{
   int indfil, indcol;

   for ( indfil = 0; indfil < DIMENSION; indfil ++ )
   {
      for ( indcol = 0; indcol < DIMENSION; indcol ++ )
      {
         cuadro2[indfil][indcol] = cuadro[indfil][indcol];
      }
   }
}

int main()
{
   srand(time(NULL));
   int matriz[DIMENSION][DIMENSION];
   int matrizenemiga[DIMENSION][DIMENSION];

   initcuadro(matriz, DIMENSION, VALINI);
   movimientos(matriz, matrizenemiga, DIMENSION, 40, 8);
   return 0;
}
