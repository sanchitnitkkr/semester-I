package labFiles;

enum AccountType {
    SAVINGS("savings"),
    CURRENT("curren");

    private final String value;

    AccountType(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }
}

class BaseAccount {
    private String customerName;
    private String accountNumber;
    private AccountType accountType;

    public String getAccountNumber() {
        return accountNumber;
    };

    public AccountType getAccountType() {
        return accountType;
    }

    public String getCustomerName() {
        return customerName;
    }
};

class CurrentAccount extends BaseAccount {
    private int balance;
    

    public int getBalance() {
        return balance;
    }

    private void setBalance(int balance) {
        this.balance = balance;
    }

    public void displayBalance() {
        System.out.println("Current balance is => " + getBalance());
    }

    private boolean withdrawlAllowed() {
        return false;
    }

    private boolean checkBookFacilityAllowed() {
        return true;
    }

}

class SavingsAccount extends BaseAccount {
    private int balance;
    private int interestRate;

    public int getBalance() {
        return balance;
    };

    private void setBalance(int balance) {
        this.balance = balance;
    };

    public void displayBalance() {
        System.out.println("Current balance is => " + getBalance());
    }

    private int computeInterest() {
        return (this.balance * this.interestRate) / 100;
    }

    private void depositInterest() {
        this.setBalance(this.getBalance() + this.computeInterest());
    }

    private boolean withdrawlAllowed() {
        return true;
    }

    int withdraw(int withdrawlAmount) {
        if (!withdrawlAllowed()) {
            throw new Error("Witdrawl is not allowed");
        }
        if (withdrawlAmount <= getBalance()) {
            setBalance(getBalance() - withdrawlAmount);
            return getBalance();
        } else {
            throw new Error("Withdrawl amount exceeds the balance");
        }
    }
}

public class W4_Q5 {

}
