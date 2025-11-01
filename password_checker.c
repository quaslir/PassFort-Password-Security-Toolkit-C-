#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
int introduction(void) {
    int choice;
    puts("===========================================");
    puts("           PASSWORD SECURITY TOOL          ");
    puts("===========================================");
    puts("1: Evaluate password strength");
    puts("2: Analyze and improve your password");
    puts("3: Generate a secure password");   
    puts("4: Try to crack your password");
    puts("5: Exit the program");
    puts("===========================================");
    puts("Enter your choice (1–5): ");
    scanf("%d", &choice);
    while(getchar() != '\n');
    return choice;
}
bool is_empty(char string[], size_t size) {
    int count = 0;
    for(int i = 0; string[i]; i++) {
        if(isalnum(string[i])) count++;
    }
    return true ? count == 0 : false;
}
int length_checker(const char string[]) {
    if(strlen(string) < 8) return 0;
    else if(strlen(string) <= 10) return 2;
    else if(strlen(string) <= 14) return 4;
    return 6;
}
int has_lower(const char string[]) {
    for(int i = 0; string[i]; i++) {
        if(islower(string[i])) return 1;
    }
    return 0;
}
int has_upper(const char string[]) {
    for(int i = 0; string[i]; i++) {
        if(isupper(string[i])) return 1;
    }
    return 0;
}
int has_digit(const char string[]) {
    for(int i = 0; string[i]; i++) {
        if(isdigit(string[i])) return 1;
    }
    return 0;
}
int has_special(const char string[]) {
    for(int i = 0; string[i]; i++) {
        if(!isalpha(string[i]) && !isspace(string[i])) return 2;
    }
    return 0;
}
char upper_generator(void) {
    return 'A' + rand() % 26;
}
char lower_generator(void) {
    return 'a' + rand() % 26;
}
char digit_generator(void) {
        return '0' + rand() % 10;
}
int random_int(int min, int max) {
    return min + rand() % (max-min+1);
}
char special_generator(void) {
    return '!' + rand() % 94;
}
bool popular_pass_checker(const char string[]) {
    const int CAP = 100;
    const char *basic_passwords[] = {"123456","password","123456789","12345678","12345","111111","1234567","sunshine",
  "qwerty","iloveyou","princess","admin","welcome","666666","abc123","football",
  "123123","monkey","654321","!@#$%^&*","charlie","aa123456","donald","password1",
  "qwerty123","zxcvbnm","1q2w3e","login","letmein","football1","passw0rd","starwars",
  "master","hello","freedom","whatever","qazwsx","trustno1","6543210","lovely",
  "michael","zaq1zaq1","baseball","dragon","shadow","superman","killer","maggie",
  "pokemon","batman","access","flower","jesus","ninja","mustang","password123",
  "thomas","robert","hannah","andrew","tigger","jordan","summer","secret",
  "charles","daniel","computer","michelle","jennifer","pepper","joshua","killer1",
  "ginger","harley","mickey","samsung","internet","chelsea","soccer","solo",
  "sparky","password2","q1w2e3r4","baseball1","11111111","121212","qwertyuiop",
  "555555","1111111","liverpool","freddy","nicole","william","victoria","999999",
  "147258","147258369", NULL};
        for(int i = 0; basic_passwords[i]; i++) {
            if(strcmp(basic_passwords[i], string) ==0 ) return true;
        }
        return false;
 }
int strength_counter(const char string[]) {
    if(popular_pass_checker(string)) return -1;
    return length_checker(string) + has_lower(string) + has_upper(string) + has_digit(string) + has_special(string);
}
void password_checker_basic() {
    char string[2000];
    puts("Enter a password to check strength: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    if(is_empty(string, sizeof(string))) {
        puts("You did not enter password.");
        return;
    }
    int strlength_calc = strength_counter(string);
    if(strlength_calc == -1) {puts("Your password is among 100 popular ones"); return;}
    printf("\nYour password strength is %d / 11\n", strlength_calc);
}
char get_random_symbol(void) {
    char c;
int res = random_int(0,3);
            switch(res) {
                case 0 :
                    c = lower_generator();
                    break;
                
                case 1: 
                    c = upper_generator();
                    break;
                
                case 2: 
                     c = digit_generator();
                    break;
                
                case 3: 
                    c = special_generator();
                    break;
            }
            return c;
}
char *password_checker_improver() {
    char string[2000];
    puts("2: Analyze and improve your password");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    if(is_empty(string, sizeof(string))) {
        return NULL;
    }
    int size = strlen(string);
    char *improved_pass = malloc(size + 10);
    if(!improved_pass) return NULL;
    strcpy(improved_pass, string);
    if(!has_lower(string)) {
        size++;
        improved_pass[size] = '\0';
        int pos = random_int(0, size - 1);
        char c = lower_generator();
        while(pos < size) {
        char temp = improved_pass[pos];
        improved_pass[pos] = c;
        c = temp;
        pos++;
        }
    }
    if(!has_upper(string)) {
        size++;
        improved_pass[size] = '\0';
        int pos = random_int(0, size - 1);
        char c = upper_generator();
        while(pos < size) {
        char temp = improved_pass[pos];
        improved_pass[pos] = c;
        c = temp;
        pos++;
        }
    }
    if(!has_digit(string)) {
        size++;
        improved_pass[size] = '\0';
        int pos = random_int(0, size - 1);
        char c = digit_generator();
        while(pos < size) {
        char temp = improved_pass[pos];
        improved_pass[pos] = c;
        c = temp;
        pos++;
        }
    }
    if(!has_special(string)) {
        size++;
        improved_pass[size] = '\0';
        int pos = random_int(0, size - 1);
        char c = special_generator();
        while(pos < size) {
        char temp = improved_pass[pos];
        improved_pass[pos] = c;
        c = temp;
        pos++;
        }
    }
    if(length_checker(string) < 2) {
        const int adder = 4;
        int pos;
        char c;
       
        for(int i = 0; i < adder; i++) {
            size++;
             improved_pass[size] = '\0';
            pos = random_int(0, size-1);
            char c = get_random_symbol();
            while(pos<size) {
                char temp = improved_pass[pos];
                improved_pass[pos] = c;
                c = temp;
                pos++;
            }
        }
    }
    return improved_pass;

}
char *password_generator() {
    printf("Enter a number of symbols in password: ");
    unsigned int size, temp;
    scanf("%d", &temp);
    while(temp < 0 || temp > INT_MAX) {
        printf("\nPlease enter a valid number of symbols: ");
        scanf("%d", &temp);
    }
    size= temp;
    while(getchar() != '\n');
    char *password = malloc(size + 1);
    for(int i = 0; i < size; i++) {
        char c = get_random_symbol();
        password[i] = c;
    }
    return password;
}
void password_cracker(void) {
    
}
int main() {
    srand(time(NULL));
    int c;
    puts("Welcome to password checker! Please enter your option");
    for(;;) {
    c = introduction();
    switch(c) {
        case 1: password_checker_basic();
        break;
        case 2: {
        char *res = password_checker_improver();
        if(res != NULL) {
        puts(res);
        free(res);
        }
            puts("You did not enter password.");
        break;
        }
        case 3: {
            char *password = password_generator();
            printf("\n%27s\n", password);
            free(password);
            break;
        }
        case 4: {
            char pass[1000];
            time_t t0 = time(NULL);
            printf("Enter your password you want to try cracking: ");
            fgets(pass, sizeof pass, stdin);
            pass[strcspn(pass, "\n")] = '\0';
            if(is_empty(pass, sizeof(pass))) {
            puts("You did not enter password.");
            break;
             }
            char buf[65536];
            const char *filename = ""; // You can use rockyou.txt or your own password database.
            FILE *file = fopen(filename, "r");
            if(!file) {
                puts("Error occured while opening a local base");
                break;
            }
            bool cracked = false;
            while(fgets(buf, sizeof buf, file)) {
                buf[strcspn(buf, "\r\n")] ='\0';
                puts(buf);
                if(strcmp(pass, buf) == 0) {
                   cracked = true;
                    break;
                }
        }
        time_t t1 = time(NULL);
        cracked == true ? printf("\nYour password was cracked in %ld seconds\n", t1 - t0) : printf("\nYour password is safe\n");
            fclose(file);
            break;
            }
        
        
        case 5: 
        system("clear");
        return 0;
        default: break;
    }
}
    return 0;
}