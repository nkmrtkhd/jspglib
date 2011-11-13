package jspglib;

public class JSpgLib {
  /**
   *
   * @auther nkmrtkhd
   *
   */
  static {
    System.loadLibrary("interfaceJSpgLib");
  }

  /**
   * find primitive lattice and atoms.
   * @return number of primitive atoms
   * @param lattice { ax, bx, cx,
   *                  ay, by, cy,
   *                  az, bz, cz}
   * @param position { r1x, r1y, r1z,
   *                   r2x, r2y, r2z,
   *                   ...}
   * @param types { atom-1 type, atom-2 type, ...}
   * @param num_atom number of atoms
   * @param symprec precise of symmetry
   */
  public native int findPrimitive(double[] lattice,double[] position,int[] types,int num_atom,double symprec);

  /**
   * refine cell
   * @return number of primitive atoms
   * @param lattice { ax, bx, cx,
   *                  ay, by, cy,
   *                  az, bz, cz}
   * @param position { r1x, r1y, r1z,
   *                   r2x, r2y, r2z,
   *                   ...}
   * @param types { atom-1 type, atom-2 type, ...}
   * @param num_atom number of atoms
   * @param symprec precise of symmetry
   */
  public native int refineCell(double[] lattice,double[] position,int[] types,int num_atom,double symprec);
  /**
   * get multiplicity
   * @return number of primitive atoms
   * @param lattice { ax, bx, cx,
   *                  ay, by, cy,
   *                  az, bz, cz}
   * @param position { r1x, r1y, r1z,
   *                   r2x, r2y, r2z,
   *                   ...}
   * @param types { atom-1 type, atom-2 type, ...}
   * @param num_atom number of atoms
   * @param symprec precise of symmetry
   */
  public native int getMultiplicity(double[] lattice,double[] position,int[] types,int num_atom,double symprec);

  /**
   * get symmetry operations
   * @return number of primitive atoms
   * @param rotation rotation matrix ={ R1_11,R1_12,R1_13,R1_21,R1_22,R1_23,R1_31,R1_32,R1_33,
   *                                    R2_11,R2_12,R2_13,R2_21,R2_22,R2_23,R2_31,R2_32,R2_33,
   *                                    ...}
   * @param translation translation vector={x1,y1,z1, x2,y2,z2, ...}
   * @param max_size maximum size of rotation and translation
   * @param lattice { ax, bx, cx,
   *                  ay, by, cy,
   *                  az, bz, cz}
   * @param position { r1x, r1y, r1z,
   *                   r2x, r2y, r2z,
   *                   ...}
   * @param types { atom-1 type, atom-2 type, ...}
   * @param num_atom number of atoms
   * @param symprec precise of symmetry
   */
  public native int getSymmetry(int[] rotation,double[] translation,int max_size,
                                double[] lattice,double[] position,int[] types,int num_atom,double symprec);

  /**
   * return international symbol
   * @return international symbol as string
   * @param lattice { ax, bx, cx,
   *                  ay, by, cy,
   *                  az, bz, cz}
   * @param position { r1x, r1y, r1z,
   *                   r2x, r2y, r2z,
   *                   ...}
   * @param types { atom-1 type, atom-2 type, ...}
   * @param num_atom number of atoms
   * @param symprec precise of symmetry
   */
  public native String getInterNational(double[] lattice,double[] position,int[] types,int num_atom,double symprec);

  /**
   * return Shoenflies
   * @return Shoenflies symbol as string
   * @param lattice { ax, bx, cx,
   *                  ay, by, cy,
   *                  az, bz, cz}
   * @param position { r1x, r1y, r1z,
   *                   r2x, r2y, r2z,
   *                   ...}
   * @param types { atom-1 type, atom-2 type, ...}
   * @param num_atom number of atoms
   * @param symprec precise of symmetry
   */
  public native String getShoenflies(double[] lattice,double[] position,int[] types,int num_atom,double symprec);

  /**
   * show symmetry data in detail
   * @param lattice { ax, bx, cx,
   *                  ay, by, cy,
   *                  az, bz, cz}
   * @param position { r1x, r1y, r1z,
   *                   r2x, r2y, r2z,
   *                   ...}
   * @param types { atom-1 type, atom-2 type, ...}
   * @param num_atom number of atoms
   * @param symprec precise of symmetry
   */
  public native void getDataset(double[] lattice,double[] position,int[] types,int num_atom,double symprec);

  /**
   * show symmetry data in detail
   * @param lattice { ax, bx, cx,
   *                  ay, by, cy,
   *                  az, bz, cz}
   * @param position { r1x, r1y, r1z,
   *                   r2x, r2y, r2z,
   *                   ...}
   * @param types { atom-1 type, atom-2 type, ...}
   * @param num_atom number of atoms
   * @param symprec precise of symmetry
   * @param grid_point
   * @param map
   * @param mesh
   * @param is_shift
   */
  public native int getIrReciprocalMesh(double[] lattice,double[] position,int[] types,int num_atom,double symprec,
                                        int[] grid_point, int[] map, int[] mesh, int[] is_shift);


  public static void main(String[] args) {
    //System.out.println("java.library.path= "+System.getProperty("java.library.path"));
    testFindPrimitive();
    testGetSym();
    testRefineCell();
    testGetSymbol();
    //testGetIrRecprocalMesh();
  }

  static private void testFindPrimitive(){
    JSpgLib spg = new JSpgLib();
    // ax, bx, cx
    // ay, by, cy
    // az, bz, cz
    double[] lattice = { 4, 0, 0,
                         0, 4, 0,
                         0, 0, 4 };
    double[] position = {0.0, 0.0, 0.0,
                         0.5, 0.5, 0.5};
    int[] types = { 1, 1 };
    int num_atom = 2;
    double symprec = 1e-5;

    System.out.println("-- input");
    for(int i=0;i<3;i++)
      System.out.println(String.format("%f %f %f", lattice[0+3*i], lattice[1+3*i], lattice[2+3*i]));
    System.out.println("*** Example of spg_find_primitive (BCC unitcell --> primitive) ***");
    int num_primitive_atom=spg.findPrimitive(lattice,position,types,num_atom,symprec);

    System.out.println("-- java result");
    for(int i=0;i<3;i++)
      System.out.println(String.format("%f %f %f", lattice[0+3*i], lattice[1+3*i], lattice[2+3*i]));

    System.out.println("Atomic positions:");
    for (int i=0; i<num_primitive_atom; i++) {
      System.out.println(String.format("%d: %f %f %f", types[i], position[i*3+0], position[i*3+1],position[i*3+2]));
    }
    spg=null;
  }//testFindPrimitive

  static private void testGetSym(){

    double lattice[] = {4,0,0,
                        0,4,0,
                        0,0,3};
    double position[] ={0,0,0,
                        0.5,0.5,0.25,
                        0.3,0.3,0,
                        0.7,0.7,0,
                        0.2,0.8,0.25,
                        0.8,0.2,0.25,
                        0,0,0.5,
                        0.5,0.5,0.75,
                        0.3,0.3,0.5,
                        0.7,0.7,0.5,
                        0.2,0.8,0.75,
                        0.8,0.2,0.75};

    int types[] = {1,1,2,2,2,2,1,1,2,2,2,2};
    int num_atom = 12;
    int max_size = 50;
    int[] rotation=new int[max_size*3*3];
    double[] translation=new double[max_size*3];
    double[] origin_shift = { 0.1, 0.1, 0 };
    double symprec = 1e-5;

    for (int i = 0; i < num_atom; i++ ) {
      for (int j = 0; j < 3; j++ )position[3*i+j] += origin_shift[j];
    }

    JSpgLib spg = new JSpgLib();
    System.out.println("*** Example of spg_get_symmetry (Rutile two unit cells) ***");
    int size=spg.getSymmetry(rotation,translation,max_size,
                             lattice,position,types,num_atom,symprec);

    for (int i = 0; i < size; i++) {
      System.out.println(String.format("--- %d ---", i + 1));
      for (int j = 0; j < 3; j++)
        System.out.println(String.format("%2d %2d %2d", rotation[i*3*3+j*3+0], rotation[i*3*3+j*3+1], rotation[i*3*3+j*3+2]));
      System.out.println(String.format("%f %f %f", translation[i*3+0], translation[i*3+1],translation[i*3+2]));
    }
    spg=null;
  }

  static private void testRefineCell(){

    double[] lattice = { 0, 2, 2,
                         2, 0, 2,
                         2, 2, 0 };
    /* 4 times larger memory space must be prepared. */
    double[] position=new double[4*3];
    int[] types=new int[4];
    int num_atom = 1;
    double symprec = 1e-5;

    position[0] = 0;
    position[1] = 0;
    position[2] = 0;
    types[0] = 1;


    System.out.println("*** Example of spg_refine_cell ***");

    JSpgLib spg = new JSpgLib();
    int num_atom_bravais=spg.refineCell(lattice,position,types,num_atom,symprec);

    System.out.println("Lattice parameter:");
    for (int i = 0; i < 3; i++ ) {
      System.out.println(String.format("%f %f %f", lattice[0+3*i], lattice[1+3*i], lattice[2+3*i]));
    }
    System.out.println("Atomic positions:");
    for (int  i = 0; i<num_atom_bravais; i++ ) {
      System.out.println(String.format("%d: %f %f %f", types[i], position[i*3+0], position[i*3+1],position[i*3+2]));
    }
  }

  static void testGetMulti(){
    double[] lattice = { 4, 0, 0,
                         0, 4, 0,
                         0, 0, 4};
    double[] position = {
      0, 0, 0,
      0.5, 0.5, 0.5
    };
    int types[] = { 1, 2 };
    int num_atom = 2;
    double symprec=1e-5;

    JSpgLib spg = new JSpgLib();
    int size=spg.getMultiplicity(lattice,position,types,num_atom,symprec);
    System.out.println("*** Example of spg_get_multiplicity ***");
    System.out.println(String.format("Number of symmetry operations: %d", size));
    spg=null;
  }

  static void testGetSymbol(){
    double[] lattice = {4,0,0,
                        0,4,0,
                        0,0,3};
    double[] position ={0,0,0,
                        0.5,0.5,0.5,
                        0.3,0.3,0,
                        0.7,0.7,0,
                        0.2,0.8,0.5,
                        0.8,0.2,0.5,
    };
    int types[] = {1,1,2,2,2,2};
    int num_atom = 6;
    String symbol="hogehoge";
    double symprec=1e-5;

    JSpgLib spg = new JSpgLib();
    System.out.println("*** Example of spg_get_international ***");
    String in=spg.getInterNational(lattice,position,types,num_atom,symprec);
    System.out.println(in);

    System.out.println("*** Example of spg_get_schoenflies ***:");
    String sh=spg.getShoenflies(lattice,position,types,num_atom,symprec);
    System.out.println(sh);

    spg.getDataset(lattice,position,types,num_atom,symprec);
  }

  static void testGetIrRecprocalMesh(){

    double[] lattice = {4,0,0,
                        0,4,0,
                        0,0,3};
    double[] position =
      {0,0,0,
       0.5,0.5,0.5,
       0.3,0.3,0,
       0.7,0.7,0,
       0.2,0.8,0.5,
       0.8,0.2,0.5,
      };
    int types[] = {1,1,2,2,2,2};
    int num_atom = 6;
    double symprec=1e-5;

    int m=100;
    int[] grid_point=new int[m*m*m*3];
    int[] map=new int[m*m*m];
    int mesh[] = { 250,250,250, };
    int is_shift[] = { 1, 1, 1 };

    JSpgLib spg = new JSpgLib();
    int num_ir=spg.getIrReciprocalMesh(lattice,position,types,num_atom,symprec,
                                       grid_point,map,mesh,is_shift);

    System.out.println("Number of irreducible k-points of Rutile with");
    System.out.println(String.format("8x8x8 Monkhorst-Pack mesh is %d.", num_ir));

    spg=null;
  }

}
