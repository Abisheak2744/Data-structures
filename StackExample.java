import java.util.*;

public class StackExample {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        Scanner scanner = new Scanner(System.in);

        boolean running = true;
        while (running) {
            System.out.println("\nStack Operations:");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Check if empty");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the element to push: ");
                    int element = scanner.nextInt();
                    stack.push(element);
                    System.out.println(element + " pushed into the stack.");
                    break;
                case 2:
                    if (stack.isEmpty()) {
                        System.out.println("Stack is empty. Cannot pop element.");
                    } else {
                        int poppedElement = stack.pop();
                        System.out.println(poppedElement + " popped from the stack.");
                    }
                    break;
                case 3:
                    if (stack.isEmpty()) {
                        System.out.println("Stack is empty. Cannot peek element.");
                    } else {
                        int topElement = stack.peek();
                        System.out.println("Top Element: " + topElement);
                    }
                    break;
                case 4:
                    boolean isEmpty = stack.isEmpty();
                    System.out.println("Is Stack Empty? " + isEmpty);
                    break;
                case 5:
                    running = false;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }

        System.out.println("Exiting the program.");
    }
}


  
