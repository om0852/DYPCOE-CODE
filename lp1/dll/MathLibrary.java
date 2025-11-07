public class MathLibrary {
    // Step 1: Declare native method
    public native int add(int a, int b);

    // Step 2: Load the DLL
    static {
        System.loadLibrary("mathdll");  // loads mathdll.dll
    }

    // Step 3: Test the native method
    public static void main(String[] args) {
        MathLibrary obj = new MathLibrary();
        int result = obj.add(10, 20);
        System.out.println("Sum = " + result);
    }
}
