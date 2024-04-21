class CheckArgument extends Exception {
    public CheckArgument(String message) {
        super(message);
    }
}

class Q4 {
    public static void main(String[] args) {
        int sum = 0;
        if (args.length < 4) {
            try {
                throw new CheckArgument("Less than four arguments passed through command line.");
            } catch (CheckArgument e) {
                System.out.println(e.getMessage());
            }
        } else {
            for (int i = 0; i < args.length; i++) {
                int num = Integer.parseInt(args[i]);
                sum += num * num;
            }
            System.out.println("The addition of squares of all four elements is " + sum);
        }
    }
}