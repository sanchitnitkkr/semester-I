package labFiles;

import java.util.UUID;

class AccountException extends RuntimeException {
    AccountException(String message) {
        super(message);
    }
}

class DepositCheckException extends AccountException {
    DepositCheckException(String message) {
        super(message);
    }
}

class WithdrawCheckException extends AccountException {
    WithdrawCheckException(String message) {
        super(message);
    }
}

class AddCompoundInterestException extends AccountException {
    AddCompoundInterestException(String message) {
        super(message);
    }
}

class DepositMoneyException extends AccountException {
    DepositMoneyException(String message) {
        super(message);
    }
}

class WithdrawMoneyException extends AccountException {
    WithdrawMoneyException(String message) {
        super(message);
    }
}

enum AccountType {
    SAVINGS("savings"),
    CURRENT("current");

    private final String value;

    AccountType(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }
}

class Cheque {
    private enum Status {
        DEPOSITED, CANCELLED, WITHDRAWN
    }

    private UUID checkID;
    private String issuedTo;
    private int amount;
    private Status status = Status.DEPOSITED;

    Cheque(String issuedTo, int amount) {
        UUID uuid = UUID.randomUUID();
        this.checkID = uuid;
        this.issuedTo = issuedTo;
        this.amount = amount;
        this.status = Status.DEPOSITED;
    }

    public int getAmount() {
        return amount;
    }

    public UUID getCheckID() {
        return checkID;
    }

    public String getIssuedTo() {
        return issuedTo;
    }

    public Status getStatus() {
        return status;
    }

    public void cancelCheque(Cheque cheque) {
        this.status = Status.CANCELLED;
    }
}

interface CheckBookFacility {
    Cheque depositCheque(String issuedTo, int amount) throws DepositCheckException;

    void cancelCheque(Cheque cheque) throws WithdrawCheckException;
}

interface CompoundInterestFacility {
    void addCompoundInterest() throws AddCompoundInterestException;
}

interface TransactionFacility {
    void deposit(int amount) throws DepositMoneyException;

    void withdraw(int amount) throws WithdrawMoneyException;
}

abstract class BaseAccount {
    private String customerName;
    private String accountNumber;
    private AccountType accountType;

    BaseAccount(String customerName, String accountNumber, AccountType accountType) {
        this.customerName = customerName;
        this.accountNumber = accountNumber;
        this.accountType = accountType;
    }

    abstract void displayBalance();

    abstract void imposePenaltyOnLowBalance();

    public String getAccountNumber() {
        return accountNumber;
    };

    public AccountType getAccountType() {
        return accountType;
    }

    public String getCustomerName() {
        return customerName;
    }

    protected void checkWithdrawAllowedElseThrowError(int balance, int amount) throws WithdrawMoneyException {
        if (amount < 0) {
            throw new WithdrawMoneyException("Invalid withdraw amount");
        }

        if (balance < amount) {
            throw new WithdrawMoneyException("Not enough balance");
        }
    }
};

class CurrentAccount extends BaseAccount implements CheckBookFacility, TransactionFacility {
    private int balance;

    CurrentAccount(String customerName, String accountNumber, AccountType accountType, int balance) {
        super(customerName, accountNumber, accountType);
        this.balance = balance;
    }

    public int getBalance() {
        return balance;
    }

    private void setBalance(int balance) {
        this.balance = balance;
    }

    @Override
    void imposePenaltyOnLowBalance() {
        if (getBalance() <= 2000) {
            setBalance(balance - 50);
        }
    }

    @Override
    public void displayBalance() {
        System.out.println("Current balance is => " + getBalance());
    }

    @Override
    public Cheque depositCheque(String issuedToAccountNumber, int amount) {
        return new Cheque(issuedToAccountNumber, amount);
    }

    @Override
    public void cancelCheque(Cheque cheque) throws WithdrawCheckException {
        this.cancelCheque(cheque);
    }

    @Override
    public void withdraw(int withdrawlAmount) throws WithdrawMoneyException {
        checkWithdrawAllowedElseThrowError(getBalance(), withdrawlAmount);

        int updatedAmt = getBalance() - withdrawlAmount;
        setBalance(updatedAmt);

    }

    @Override
    public void deposit(int depositAmount) throws DepositMoneyException {
        int updatedBal = getBalance() + depositAmount;
        setBalance(updatedBal);

    }
}

class SavingsAccount extends BaseAccount implements CompoundInterestFacility, TransactionFacility {
    private int balance;
    private final int interestRate = 6;

    SavingsAccount(String customerName, String accountNumber, AccountType accountType, int balance) {
        super(customerName, accountNumber, accountType);
        this.balance = balance;
    }

    public int getBalance() {
        return balance;
    };

    private void setBalance(int balance) {
        this.balance = balance;
    };

    private int computeInterest() {
        return (this.balance * this.interestRate) / 100;
    }

    @Override
    void imposePenaltyOnLowBalance() {
        if (getBalance() <= 2000) {
            setBalance(balance - 50);
        }
    }

    @Override
    public void displayBalance() {
        System.out.println("Current balance is => " + getBalance());
    }

    @Override
    public void addCompoundInterest() {
        setBalance(getBalance() + this.computeInterest());
    }

    @Override
    public void withdraw(int withdrawlAmount) {
        checkWithdrawAllowedElseThrowError(getBalance(), withdrawlAmount);
        setBalance(getBalance() - withdrawlAmount);
    }

    @Override
    public void deposit(int depositAmount) throws DepositMoneyException {
        int updatedBal = getBalance() + depositAmount;
        setBalance(updatedBal);

    }
}

public class W4_Q5 {
    public static void main(String[] args) {
        SavingsAccount savingsAccount = new SavingsAccount("Sanchit", "172390274", AccountType.SAVINGS, 5000);
        savingsAccount.displayBalance();
        savingsAccount.withdraw(4000);
        savingsAccount.displayBalance();
        savingsAccount.deposit(2000);
        savingsAccount.displayBalance();

        savingsAccount.addCompoundInterest(); // Execute this in a cron job which runs every x days
        savingsAccount.imposePenaltyOnLowBalance(); // Execute this in a cron job which runs every x days

        savingsAccount.displayBalance();
    }

}
