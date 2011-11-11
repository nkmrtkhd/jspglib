#include <jni.h>
#include "jspglib_JSpgLib.h"
#include <stdio.h>
#include <string.h>
#include "spglib.h"



JNIEXPORT int JNICALL Java_jspglib_JSpgLib_findPrimitive
(JNIEnv *env, jobject obj,
 jdoubleArray latticeArg,
 jdoubleArray positionArg,
 jintArray typesArg,
 jint num_atom,
 jdouble symprec)
{
  int i,j;

  //copy arg to work variable
  double lattice[3][3];
  jdouble *l = (*env)->GetDoubleArrayElements(env, latticeArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) lattice[i][j]= l[3*i+j];

  int plength=(*env)->GetArrayLength(env,positionArg);
  double position[plength][3];
  jdouble *p = (*env)->GetDoubleArrayElements(env, positionArg, 0);
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++) position[i][j]= p[3*i+j];

  jint *types = (*env)->GetIntArrayElements(env, typesArg, 0);

  //process
  int num_primitive_atom=spg_find_primitive(lattice, position, types, num_atom, symprec);


  //write original array
  for(i=0;i<3;i++)for(j=0; j<3; j++)l[3*i+j]=lattice[i][j];
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++)p[3*i+j]=position[i][j];
  (*env)->ReleaseDoubleArrayElements(env, latticeArg,l, 0);
  (*env)->ReleaseDoubleArrayElements(env, positionArg,p, 0);
  (*env)->ReleaseIntArrayElements(env, typesArg, types, 0);

  return num_primitive_atom;
}

JNIEXPORT int JNICALL Java_jspglib_JSpgLib_refineCell
(JNIEnv *env, jobject obj,
 jdoubleArray latticeArg,
 jdoubleArray positionArg,
 jintArray typesArg,
 jint num_atom,
 jdouble symprec)
{

  int i,j;

  //copy arg to work variable
  double lattice[3][3];
  jdouble *l = (*env)->GetDoubleArrayElements(env, latticeArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) lattice[i][j]= l[3*i+j];

  int plength=(*env)->GetArrayLength(env,positionArg);
  double position[plength][3];
  jdouble *p = (*env)->GetDoubleArrayElements(env, positionArg, 0);
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++) position[i][j]= p[3*i+j];

  jint *types = (*env)->GetIntArrayElements(env, typesArg, 0);

  /* lattice, position, and types are overwirtten. */
  int num_atom_bravais = spg_refine_cell( lattice,
                                          position,
                                          types,
                                          num_atom,
                                          symprec );

  //write original array
  for(i=0;i<3;i++)for(j=0; j<3; j++)l[3*i+j]=lattice[i][j];
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++)p[3*i+j]=position[i][j];
  (*env)->ReleaseDoubleArrayElements(env, latticeArg,l, 0);
  (*env)->ReleaseDoubleArrayElements(env, positionArg,p, 0);
  (*env)->ReleaseIntArrayElements(env, typesArg, types, 0);

  return num_atom_bravais;

}

JNIEXPORT jstring JNICALL Java_jspglib_JSpgLib_getInterNational
(JNIEnv *env, jobject obj,
 jdoubleArray latticeArg,
 jdoubleArray positionArg,
 jintArray typesArg,
 jint num_atom,
 jdouble symprec)

{

  int i,j;

  //copy arg to work variable
  double lattice[3][3];
  jdouble *l = (*env)->GetDoubleArrayElements(env, latticeArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) lattice[i][j]= l[3*i+j];

  int plength=(*env)->GetArrayLength(env,positionArg);
  double position[plength][3];
  jdouble *p = (*env)->GetDoubleArrayElements(env, positionArg, 0);
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++) position[i][j]= p[3*i+j];

  jint *types = (*env)->GetIntArrayElements(env, typesArg, 0);

  char symbol[21];

  //process
  int num_spg = spg_get_international(symbol, lattice, position, types, num_atom, symprec);

  //set string
  char result[64];
  if(num_spg>0)
    sprintf(result,"%s (%d)",symbol,num_spg);
  else
    sprintf(result,"Space group could not be found.");

  //write original array
  for(i=0;i<3;i++)for(j=0; j<3; j++)l[3*i+j]=lattice[i][j];
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++)p[3*i+j]=position[i][j];
  (*env)->ReleaseDoubleArrayElements(env, latticeArg,l, 0);
  (*env)->ReleaseDoubleArrayElements(env, positionArg,p, 0);
  (*env)->ReleaseIntArrayElements(env, typesArg, types, 0);

  return (*env)->NewStringUTF(env,result);
}

JNIEXPORT jstring JNICALL Java_jspglib_JSpgLib_getShoenflies
(JNIEnv *env, jobject obj,
 jdoubleArray latticeArg,
 jdoubleArray positionArg,
 jintArray typesArg,
 jint num_atom,
 jdouble symprec)
{

  int i,j;

  //copy arg to work variable
  double lattice[3][3];
  jdouble *l = (*env)->GetDoubleArrayElements(env, latticeArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) lattice[i][j]= l[3*i+j];

  int plength=(*env)->GetArrayLength(env,positionArg);
  double position[plength][3];
  jdouble *p = (*env)->GetDoubleArrayElements(env, positionArg, 0);
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++) position[i][j]= p[3*i+j];

  jint *types = (*env)->GetIntArrayElements(env, typesArg, 0);

  char symbol[10];
  spg_get_schoenflies(symbol, lattice, position, types, num_atom, 1e-5);


  //set string
  char result[64];
  sprintf(result,"Schoenflies: %s", symbol);

  //write original array
  for(i=0;i<3;i++)for(j=0; j<3; j++)l[3*i+j]=lattice[i][j];
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++)p[3*i+j]=position[i][j];
  (*env)->ReleaseDoubleArrayElements(env, latticeArg,l, 0);
  (*env)->ReleaseDoubleArrayElements(env, positionArg,p, 0);
  (*env)->ReleaseIntArrayElements(env, typesArg, types, 0);

  return (*env)->NewStringUTF(env,result);
}

JNIEXPORT int JNICALL Java_jspglib_JSpgLib_getMultiplicity
(JNIEnv *env, jobject obj,
 jdoubleArray latticeArg,
 jdoubleArray positionArg,
 jintArray typesArg,
 jint num_atom,
 jdouble symprec)
{
  int i,j;

  //copy arg to work variable
  double lattice[3][3];
  jdouble *l = (*env)->GetDoubleArrayElements(env, latticeArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) lattice[i][j]= l[3*i+j];

  int plength=(*env)->GetArrayLength(env,positionArg);
  double position[plength][3];
  jdouble *p = (*env)->GetDoubleArrayElements(env, positionArg, 0);
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++) position[i][j]= p[3*i+j];

  jint *types = (*env)->GetIntArrayElements(env, typesArg, 0);

  //process
  int size = spg_get_multiplicity(lattice, position, types, num_atom, 1e-5);

  //write original array
  for(i=0;i<3;i++)for(j=0; j<3; j++)l[3*i+j]=lattice[i][j];
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++)p[3*i+j]=position[i][j];
  (*env)->ReleaseDoubleArrayElements(env, latticeArg,l, 0);
  (*env)->ReleaseDoubleArrayElements(env, positionArg,p, 0);
  (*env)->ReleaseIntArrayElements(env, typesArg, types, 0);

}


JNIEXPORT int JNICALL Java_jspglib_JSpgLib_getSymmetry
(JNIEnv *env, jobject obj,
 jintArray rotationArg,
 jdoubleArray translationArg,
 jint max_size,
 jdoubleArray latticeArg,
 jdoubleArray positionArg,
 jintArray typesArg,
 jint num_atom,
 jdouble symprec)

{
  int i,j,k;

  //copy arg to work variable

  int rotation[max_size][3][3];
  jint *r = (*env)->GetIntArrayElements(env, rotationArg, 0);
  for(i=0;i<max_size;i++)for(j=0; j<3; j++)for(k=0; k<3; k++)
                                             rotation[i][j][k]= r[3*3*i+3*j+k];

  double translation[max_size][3];
  jdouble *t = (*env)->GetDoubleArrayElements(env, translationArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) translation[i][j]= t[3*i+j];


  double lattice[3][3];
  jdouble *l = (*env)->GetDoubleArrayElements(env, latticeArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) lattice[i][j]= l[3*i+j];

  int plength=(*env)->GetArrayLength(env,positionArg);
  double position[plength][3];
  jdouble *p = (*env)->GetDoubleArrayElements(env, positionArg, 0);
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++) position[i][j]= p[3*i+j];

  jint *types = (*env)->GetIntArrayElements(env, typesArg, 0);


  //process
  int size = spg_get_symmetry( rotation, translation, max_size,
                               lattice, position, types, num_atom, symprec);

  //write original array
  for(i=0;i<3;i++)for(j=0; j<3; j++)l[3*i+j]=lattice[i][j];
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++)p[3*i+j]=position[i][j];
  (*env)->ReleaseDoubleArrayElements(env, latticeArg,l, 0);
  (*env)->ReleaseDoubleArrayElements(env, positionArg,p, 0);
  (*env)->ReleaseIntArrayElements(env, typesArg, types, 0);


  return size;
}

JNIEXPORT void JNICALL Java_jspglib_JSpgLib_getDataset
(JNIEnv *env, jobject obj,
 jdoubleArray latticeArg,
 jdoubleArray positionArg,
 jintArray typesArg,
 jint num_atom,
 jdouble symprec)
{

  SpglibDataset *dataset;
  int i, j, size;

  //copy arg to work variable
  double lattice[3][3];
  jdouble *l = (*env)->GetDoubleArrayElements(env, latticeArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) lattice[i][j]= l[3*i+j];

  int plength=(*env)->GetArrayLength(env,positionArg);
  double position[plength][3];
  jdouble *p = (*env)->GetDoubleArrayElements(env, positionArg, 0);
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++) position[i][j]= p[3*i+j];

  jint *types = (*env)->GetIntArrayElements(env, typesArg, 0);

  const char *wl = "abcdefghijklmnopqrstuvwxyz";

  printf("*** Example of spg_get_dataset (Rutile two unit cells) ***:\n");
  dataset = spg_get_dataset( lattice,
                             position,
                             types,
                             num_atom,
                             symprec);

  printf("International: %s (%d)\n", dataset->international_symbol, dataset->spacegroup_number );
  printf("Hall symbol:   %s\n", dataset->hall_symbol );
  printf("Transformation matrix:\n");
  for ( i = 0; i < 3; i++ ) {
    printf("%f %f %f\n",
           dataset->transformation_matrix[i][0],
           dataset->transformation_matrix[i][1],
           dataset->transformation_matrix[i][2]);
  }
  printf("Wyckoff letters:\n");
  for ( i = 0; i < dataset->n_atoms; i++ ) {
    printf("%c ", wl[dataset->wyckoffs[i]]);
  }
  printf("\n");
  printf("Equivalent atoms:\n");
  for ( i = 0; i < dataset->n_atoms; i++ ) {
    printf("%d ", dataset->equivalent_atoms[i]);
  }
  printf("\n");

  for ( i = 0; i < dataset->n_operations; i++ ) {
    printf("--- %d ---\n", i + 1);
    for ( j = 0; j < 3; j++ ) {
      printf("%2d %2d %2d\n",
             dataset->rotations[i][j][0],
             dataset->rotations[i][j][1],
             dataset->rotations[i][j][2]);
    }
    printf("%f %f %f\n",
           dataset->translations[i][0],
           dataset->translations[i][1],
           dataset->translations[i][2]);
  }

  spg_free_dataset( dataset );

  //write original array
  for(i=0;i<3;i++)for(j=0; j<3; j++)l[3*i+j]=lattice[i][j];
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++)p[3*i+j]=position[i][j];
  (*env)->ReleaseDoubleArrayElements(env, latticeArg,l, 0);
  (*env)->ReleaseDoubleArrayElements(env, positionArg,p, 0);
  (*env)->ReleaseIntArrayElements(env, typesArg, types, 0);

  return;
}

JNIEXPORT int JNICALL Java_jspglib_JSpgLib_getIrReciprocalMesh
(JNIEnv *env, jobject obj,
 jdoubleArray latticeArg,
 jdoubleArray positionArg,
 jintArray typesArg,
 jint num_atom,
 jdouble symprec,
 jintArray grid_pointArg,
 jintArray mapArg,
 jintArray meshArg,
 jintArray is_shiftArg)
{
  int i,j;


  //copy arg to work variable
  double lattice[3][3];
  jdouble *l = (*env)->GetDoubleArrayElements(env, latticeArg, 0);
  for(i=0;i<3;i++)for(j=0; j<3; j++) lattice[i][j]= l[3*i+j];
  int plength=(*env)->GetArrayLength(env,positionArg);
  double position[plength][3];
  jdouble *p = (*env)->GetDoubleArrayElements(env, positionArg, 0);
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++) position[i][j]= p[3*i+j];
  jint *types = (*env)->GetIntArrayElements(env, typesArg, 0);


  int gl=(*env)->GetArrayLength(env,grid_pointArg);
  int grid_point[gl/3][3];
  jint *g = (*env)->GetDoubleArrayElements(env, grid_pointArg, 0);
  for(i=0;i<gl/3;i++)for(j=0; j<3; j++) grid_point[i][j]= g[3*i+j];

  jint *map = (*env)->GetIntArrayElements(env, mapArg, 0);
  jint *mesh = (*env)->GetIntArrayElements(env, meshArg, 0);
  jint *is_shift = (*env)->GetIntArrayElements(env, is_shiftArg, 0);




  int num_ir = spg_get_ir_reciprocal_mesh( grid_point,
                                           map,
                                           mesh,
                                           is_shift,
                                           1,
                                           lattice,
                                           position,
                                           types,
                                           num_atom,
                                           symprec);

  //write original array
  for(i=0;i<3;i++)for(j=0; j<3; j++)l[3*i+j]=lattice[i][j];
  for(i=0;i<plength/3;i++)for(j=0; j<3; j++)p[3*i+j]=position[i][j];
  (*env)->ReleaseDoubleArrayElements(env, latticeArg,l, 0);
  (*env)->ReleaseDoubleArrayElements(env, positionArg,p, 0);
  (*env)->ReleaseIntArrayElements(env, typesArg, types, 0);


  for(i=0;i<gl/3;i++)for(j=0; j<3; j++)g[3*i+j]=grid_point[i][j];
  (*env)->ReleaseIntArrayElements(env, grid_pointArg, g, 0);
  (*env)->ReleaseIntArrayElements(env, mapArg, map, 0);
  (*env)->ReleaseIntArrayElements(env, meshArg, mesh, 0);
  (*env)->ReleaseIntArrayElements(env, is_shiftArg, is_shift, 0);


  return num_ir;
}
