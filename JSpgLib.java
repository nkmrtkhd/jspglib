
public class JSpgLib {
    static {
      System.loadLibrary("interfaceJSpgLib");
    }

    public JSpgLib() {
      printHello();
    }

    public native void printHello();
    public native void getPrimitive(double[][] a);
    
    public static void main(String[] args) {
      JSpgLib spg = new JSpgLib();
      double a[][]={{1., 2.},
                 {3., 4.}};
      spg.getPrimitive(a);
    }
} //
