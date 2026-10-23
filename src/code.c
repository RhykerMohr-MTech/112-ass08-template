//char *AUTHOR_NAME        = (char *) "Rhyker Mohr";
//char *AUTHOR_AUTHORSHIP  = (char *) "I acknowledge that I have worked on this
// assignment independently, except where explicitly noted and referenced.
// Any collaboration or use of external resources has been properly cited.
// I am fully aware of the consequences of academic dishonesty and agree to
// abide by the university's academic integrity policy.";

// code.c — student implementation only
/* * code.c - Implementation file for Lab 8  */


#include "code.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
 * code.c - Assignment 8: File Access and Math Functions
 *
 * TODO: Include <stdio.h> (file functions), <stdlib.h> (abs),
 *       <math.h> (all other math functions) and your own "code.h".
 *
 * GENERAL RULES (apply to EVERY function below):
 *   - Check the arguments FIRST. If they are invalid, return false
 *     immediately, BEFORE calling fopen(), so the file is never touched.
 *   - Always check whether fopen() succeeded. If it did not, return false
 *     (or -1 for the functions that return int / long).
 *   - Always close every file you open, including on error paths
 *     that happen AFTER a successful fopen().
 *   - Text files: doubles are written as "%.2f\n", integers as "%d\n",
 *     one value per line.
 *   - Binary files: raw bytes only, no separators, no extra data.
 *   - Return true only if the write/read AND the close succeeded.
 *
 * OPTIONAL TIP: Many functions differ only in the math function and the
 * file mode. You may write small `static` helper functions (for example
 * "write one double as a text line using a given mode" and
 * "write an array of doubles as raw bytes using a given mode")
 * and reuse them. Helpers are not tested, and they do not go into code.h.
 */


/* ========================= PART A: Text mode ========================= */

/*
 * 1. create_abs_txt (returns bool; parameters: filename, int value)
 *    - Open the file for writing (it is created or overwritten).
 *    - Compute the absolute value of the integer with abs().
 *    - Write it as an integer followed by a newline.
 *    - Close the file and report success only if writing and closing worked.
 */
// TODO
bool create_abs_txt(const char *filename, int value)
{
   FILE *f = fopen(filename, "w");
if (f == NULL)
{
    return false;       // always check!
}
int abs_value = abs(value);

fprintf(f, "%d\n", abs_value);
fclose(f);              // always close!
return true;

}

/*
 * 2. create_fabs_txt (returns bool; parameters: filename, double value)
 *    - Same idea as the previous function, but for a double:
 *      use fabs() and write with exactly two digits after the decimal point.
 *    - Open mode: write (create / overwrite).
 */
// TODO

bool create_fabs_txt(const char *filename, double value)
{
    FILE *f = fopen(filename, "w");
if (f == NULL)
{
    return false;       // always check!
}
double fabs_value = fabs(value);

fprintf(f, "%.2f\n", fabs_value);
fclose(f);              // always close!
return true;
}

/*
 * 3. append_sqrt_txt (returns bool; parameters: filename, double value)
 *    - Invalid input: negative value -> return false, do not touch the file.
 *    - Open the file in APPEND mode, so older content stays.
 *    - Write sqrt(value) as a new line with two decimal digits.
 *    - Close and report success.
 */
// TODO
bool append_sqrt_txt(const char *filename, double value)
{
    if(value < 0)
    {
    return false;
    }

    FILE *f = fopen(filename, "a");
    if (f == NULL)
    {
    return false;       // always check!
    }
double sqrt_value = sqrt(value);

fprintf(f, "%.2f\n", sqrt_value);
fclose(f);              // always close!
return true;
}

/*
 * 4. append_pow_txt (returns bool; parameters: filename, double base, double exponent)
 *    - Invalid input: base equal to zero AND exponent negative
 *      (division by zero) -> return false, do not touch the file.
 *    - Open in APPEND mode, write pow(base, exponent) as a new line
 *      with two decimal digits, close, report success.
 */
// TODO
bool append_pow_txt(const char *filename, double base, double exponent)
{
    if (base == 0 && exponent < 0)
    {
    return false;
    }

    FILE *f = fopen(filename, "a");

    if (f == NULL)
{
    return false;       // always check!
}
double pow_value = pow(base, exponent);

fprintf(f, "%.2f\n", pow_value);
fclose(f);              // always close!
return true;
}

/*
 * 5. create_ceil_floor_txt (returns bool; parameters: filename, double value)
 *    - Open in WRITE mode (create / overwrite).
 *    - Write TWO lines: first ceil(value), then floor(value),
 *      both with two decimal digits.
 *    - Success requires that both writes AND the close worked.
 */
// TODO
bool create_ceil_floor_txt(const char *filename, double value)
{
FILE *f = fopen(filename, "w");
if (f == NULL)
{
    return false;       // always check!
}
double ceil_value = ceil(value);
double floor_value = floor(value);

fprintf(f, "%.2f\n", ceil_value);
fprintf(f, "%.2f\n", floor_value);
fclose(f);              // always close!
return true;

}

/*
 * 6. append_round_txt (returns bool; parameters: filename, double value)
 *    - Open in APPEND mode, write round(value) as a new line
 *      with two decimal digits, close, report success.
 *    - No invalid input exists for this function.
 */
// TODO
bool append_round_txt(const char *filename, double value)
{

FILE *f = fopen(filename, "a");
if (f == NULL)
{
    return false;       // always check!
}
double round_value = round(value);

fprintf(f, "%.2f\n", round_value);
fclose(f);              // always close!
return true;

}

/*
 * 7. append_fmod_txt (returns bool; parameters: filename, double x, double y)
 *    - Invalid input: y equal to zero -> return false, do not touch the file.
 *    - Open in APPEND mode, write fmod(x, y) as a new line
 *      with two decimal digits, close, report success.
 */
// TODO
bool append_fmod_txt(const char *filename, double x, double y)
{
    if(y==0)
        {
        return false;
        }
FILE *f = fopen(filename, "a");
if (f == NULL)
{
    return false;       // always check!
}
double fmod_value = fmod(x, y);

fprintf(f, "%.2f\n", fmod_value);
fclose(f);              // always close!
return true;

}

/*
 * 8. load_txt_values (returns int; parameters: filename, double array, int max_count)
 *    - Open the file for reading. If it cannot be opened, return -1.
 *    - Keep a counter of values read, starting at 0.
 *    - Repeat while the counter is below max_count: read one number
 *      with the formatted-input function. Remember that a double needs
 *      the "long float" conversion specifier. The input function returns
 *      the number of items it successfully read; stop the loop when
 *      that is not exactly 1 (end of file or bad data).
 *    - Store each value into the next slot of the array and increase the counter.
 *    - Close the file and return the counter.
 */
// TODO
int load_txt_values(const char *filename, double *arr, int max_count)
{

    FILE *f = fopen(filename, "r");
if (f == NULL)
{
    return -1;       // always check!
}

int count = 0;
double value;
while (count < max_count)
{
if (fscanf(f, "%lf", &value) != 1)
{
break;
}
arr[count] = value;
count++;
}

fclose(f);              // always close!
return count;
}

/*
 * 9. clear_file (returns bool; parameters: filename)
 *    - Think: which open mode removes all existing content
 *      and creates the file when it does not exist?
 *    - You do not need to write anything. Just open and close.
 *    - Report success only if both the open and the close worked.
 */
// TODO
bool clear_file(const char *filename)
{
    FILE *f = fopen(filename, "w");
if (f == NULL)
{
    return false;       // always check!
}

if (fclose(f) !=0)    
{
    return false;
}         // always close!


return true;
}

/* ========================= PART B: Binary mode ========================= */

/*
 * 10. create_abs_bin (returns bool; parameters: filename, int value)
 *     - Open in BINARY WRITE mode (create / overwrite).
 *     - Compute abs(value) and keep it in an int variable
 *       (you need its address to write it).
 *     - Write exactly ONE element whose size is the size of an int.
 *     - Success: fwrite reported 1 element written AND the close worked.
 */
// TODO
bool create_abs_bin(const char *filename, int value)
{
    FILE *f = fopen(filename, "wb");
if (f == NULL)
{
    return false;       // always check!
}
int abs_bin_value = abs(value);

size_t elements_written = fwrite(&abs_bin_value, sizeof(int), 1, f);

int close_status = fclose(f); // always close!

return (elements_written == 1 && close_status == 0);
}
/*
 * 11. create_fabs_bin (returns bool; parameters: filename, double value)
 *     - Same idea as above, but the stored value is a double (fabs of the input).
 *     - Open in BINARY WRITE mode.
 *     - Keep the result in a double variable and write ONE element
 *       of size sizeof(double).
 */
// TODO
bool create_fabs_bin(const char *filename, double value)
{
FILE *f = fopen("filename", "wb");
if (f == NULL)
{
    return false;       // always check!
}

double fabs_bin_value = fabs(value);

size_t elements_written = fwrite(&fabs_bin_value, sizeof(double), 1, f);

int close_status = fclose(f);  // always close!

return (elements_written == 1 && close_status == 0);


}
/*
 * 12. append_sqrt_bin (returns bool; parameters: filename, double value)
 *     - Invalid input: negative value -> return false BEFORE opening the file.
 *     - Open in BINARY APPEND mode, so older content stays.
 *     - Store sqrt(value) in a double variable and write ONE double.
 *     - Close and report success.
 */
// TODO
bool append_sqrt_bin(const char *filename, double value)
{
    if(value < 0)
    {
    return false;
    }

    FILE *f = fopen(filename, "ab");
    if (f == NULL)
    {
    return false;       // always check!
    }
double sqrt_bin_value = sqrt(value);

size_t written = fwrite(&sqrt_bin_value, sizeof(double), 1, f);
if (written != 1)
{
    fclose(f);
    return false;
}


return true;
}
/*
 * 13. append_pow_bin (returns bool; parameters: filename, double base, double exponent)
 *     - Invalid input: base equal to zero AND exponent negative
 *       -> return false, do not touch the file.
 *     - Open in BINARY APPEND mode, write pow(base, exponent) as ONE double,
 *       close, report success.
 */
// TODO
bool append_pow_bin(const char *filename, double base, double exponent)
{
if (base == 0 && exponent < 0)
    {
    return false;
    }

    FILE *f = fopen(filename, "a");

    if (f == NULL)
{
    return false;       // always check!
}
double pow_value = pow(base, exponent);

fprintf(f, "%.2f\n", pow_value);
fclose(f);              // always close!
return true;

}


/*
 * 14. create_ceil_floor_bin (returns bool; parameters: filename, double value)
 *     - Open in BINARY WRITE mode (create / overwrite).
 *     - Write TWO doubles: first ceil(value), then floor(value).
 *     - Hint: put both results in a small double array of size 2
 *       and write both elements with a SINGLE write call
 *       (count = 2), or use two separate calls.
 *     - Success requires that all writes AND the close worked.
 */
// TODO
bool create_ceil_floor_bin(const char *filename, double value)
{
    FILE *file = fopen(filename, "wb");
if (file == NULL) 
{
    return false;
}
double data[2];
data[0] = ceil(value);
data[1] = floor(value);

size_t elements_written = fwrite(data, sizeof(double), 2, file);

int close_status = fclose(file);

return (elements_written == 2) && (close_status == 0);

}


/*
 * 15. append_round_bin (returns bool; parameters: filename, double value)
 *     - Open in BINARY APPEND mode, write round(value) as ONE double,
 *       close, report success.
 *     - No invalid input exists for this function.
 */
// TODO
bool append_round_bin(const char *filename, double value)
{
 if (filename == NULL) {
        return false;
    }

    // Open file in binary append mode ("ab")
    FILE *f = fopen(filename, "ab");
    if (f == NULL) {
        return false;
    }

    // Calculate the rounded value
    double round_value = round(value);

    // Write the single double value to the file
    size_t items_written = fwrite(&round_value, sizeof(double), 1, f);

    // Close the file and capture the return status
    int close_status = fclose(f);

    // Success requires that 1 item was written and the file closed successfully
    return (items_written == 1 && close_status == 0);

}
/*
 * 16. append_fmod_bin (returns bool; parameters: filename, double x, double y)
 *     - Invalid input: y equal to zero -> return false, do not touch the file.
 *     - Open in BINARY APPEND mode, write fmod(x, y) as ONE double,
 *       close, report success.
 */
// TODO
bool append_fmod_bin(const char *filename, double x, double y)
{

if (y == 0.0 || filename == NULL) {
        return false;
    }

    // Open file in binary append mode ("ab")
    FILE *f = fopen(filename, "ab");
    if (f == NULL) {
        return false;
    }

    // Calculate the floating-point remainder of x/y
    double fmod_value = fmod(x, y);

    // Write the result as ONE double
    size_t items_written = fwrite(&fmod_value, sizeof(double), 1, f);

    // Close the file and capture the return status
    int close_status = fclose(f);

    // Success requires that 1 item was written and the file closed cleanly
    return (items_written == 1 && close_status == 0);
}
/*
 * 17. load_abs_bin (returns bool; parameters: filename, int pointer out)
 *     - Open in BINARY READ mode. If it cannot be opened, return false.
 *     - Read ONE element of size sizeof(int) directly into *out
 *       (the pointer already holds the address, so do not use & here).
 *     - Close the file (always, also when the read failed).
 *     - Return true only if exactly 1 element was read.
 *       A file that is too short makes the read function return 0.
 */
// TODO
bool load_abs_bin(const char *filename, int *out)
{
    if (filename == NULL || out == NULL) {
        return false;
    }

    // Open file in binary read mode ("rb")
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        return false;
    }

    int temp_value;

    // Read ONE integer from the binary file
    size_t items_read = fread(&temp_value, sizeof(int), 1, f);

    // Close the file
    int close_status = fclose(f);

    // Verify that the integer was read successfully and file closed properly
    if (items_read == 1 && close_status == 0) {
        // Store the absolute value into the output parameter
        *out = abs(temp_value);
        return true;
    }

    return false;
}
/*
 * 18. load_bin_values (returns int; parameters: filename, double array, int max_count)
 *     - Open in BINARY READ mode. If it cannot be opened, return -1.
 *     - Keep a counter starting at 0.
 *     - Repeat while the counter is below max_count: read ONE double
 *       into the next array slot. Stop the loop when the read function
 *       does not return 1 (end of file).
 *     - Increase the counter after every successful read.
 *     - Close the file and return the counter.
 */
// TODO

int load_bin_values(const char *filename, double *arr, int max_count)
{
    if (filename == NULL || arr == NULL || max_count <= 0)
    {
        return -1;
    }

    
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
    {
        return -1;
    }

    int counter = 0;

    // Repeat while the counter is below max_count
    while (counter < max_count)
    {
        // Read ONE double into the next array slot
        size_t read_elements = fread(&arr[counter], sizeof(double), 1, f);
        
        // Stop the loop when the read function does not return 1 (EOF or error)
        if (read_elements != 1)
        {
            break;
        }

        // Increase the counter after every successful read
        counter++;
    }

    // Close the file (ignoring close errors here since read was successful)
    fclose(f);
    
    // Return the counter
    return counter;
}

/*
 * 19. load_bin_value_at (returns bool; parameters: filename, int index, double pointer out)
 *     - Invalid input: negative index -> return false BEFORE opening the file.
 *     - Open in BINARY READ mode. If it cannot be opened, return false.
 *     - Calculate the byte offset: index multiplied by the size of a double.
 *       Convert it to long to match the type expected by the seek function.
 *     - Jump there from the BEGINNING of the file.
 *       If the seek fails, close the file and return false.
 *     - Read ONE double into *out. Close the file.
 *     - Return true only if exactly 1 element was read
 *       (a file that is too short gives 0).
 */
// TODO
bool load_bin_value_at(const char *filename, int index, double *out)
{
    if (filename == NULL || out == NULL || index < 0)
    {
        return false;
    }

    // Open in BINARY READ mode
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
    {
        return false;
    }

    // Seek directly to the byte offset of the target index
    // Each double takes up sizeof(double) bytes
    if (fseek(f, index * sizeof(double), SEEK_SET) != 0)
    {
        fclose(f);
        return false; // Index out of bounds or seek failed
    }

    // Read the single double at that position
    size_t read_elements = fread(out, sizeof(double), 1, f);

    fclose(f);

    // Return true only if 1 element was successfully read
    return (read_elements == 1);
}
/*
 * 20. get_file_size (returns long; parameters: filename)
 *     - Open in BINARY READ mode. If it cannot be opened, return -1.
 *     - Jump to the END of the file (offset 0, origin = end).
 *       If the seek fails, close the file and return -1.
 *     - Ask for the current position: at the end of the file it equals
 *       the size in bytes. Store it in a long variable.
 *     - Close the file and return the stored size.
 */
// TODO

long get_file_size(const char *filename)
{
FILE *f = fopen(filename, "rb");
if (f == NULL)
{
    return -1;       // always check!
}

if (fseek(f, 0, SEEK_END) !=0)
{
    fclose(f);
    return -1;
}

long size = ftell(f);

fclose(f);              // always close!
return size;

}