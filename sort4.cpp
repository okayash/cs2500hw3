/* Ashley Fong
CS2500 Morales
Homework 3
Due November 15th, 2024 */

#include <iostream>

using namespace std;

int m_comparisons = 0; //global variable to count comps among all merge sort calls

void swap(int& a, int& b){
    int temp = a; //temp a
    a = b; //b goes into a 
    b = temp; //value of a goes into b
}

void copy(int A[], int B[], int n){ //copy array sz n
    for(int i = 0; i < n; i++){
        B[i] = A[i];
    }
}

//bubble sort
void bubble_sort(int A[], int n){ //algo based on notes
  int b_comparisons = 0; //bubble sort comparisons
  int b_swaps = 0; //bubble sort swaps
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n-1-i; j++){
        b_comparisons++; //comparison here so add
        if(A[j+1] < A[j]){ //if j adj value is smaller
            swap(A[j+1], A[j]); //swap adjacent out of order vals
            b_swaps++; //add swaps
        }
    }
  }
  cout << b_comparisons << "\t";  //print
  cout << b_swaps << endl;
}
//selection sort
void selection_sort(int A[], int n){ //algorithm based on class
  int s_comparisons = 0;
  int s_swaps = 0;
  for(int i = 0; i < n-1; i++){
    int min = i; //select a min so far
    for(int j = i+1; j < n; j++){
        s_comparisons++; // comparison here so add
        if(A[i] < A[min]){  
            min = j; //min moves to val after current min
        }
    }
    swap(A[i], A[min]); //swap into place
    s_swaps++; //swap here
  }
  cout << s_comparisons << "\t";
  cout << s_swaps << endl;
}

//insertion sort
void insertion_sort(int A[], int n){ //algorithm from class
    int i_comparisons = 0;
    int i_assignments = 0;
    int j;
    for(int i = 1; i < n; i++){
        int v = A[i]; //to be inserted
        j = i-1; 
        while(j >= 0 && A[j] > v){
            i_comparisons++; //add a comparison
            i_assignments++; //add an assignment
            A[j+1] = A[j]; //shift values
            j -= 1; //decr j
        }
        if(j >= 0)
            i_comparisons++; //increment for when while loop doesn't exc
        i_assignments++; //assignment is done (in next line) so add
        A[j+1] = v; //insert v into correct spot
    }
    cout << i_comparisons << "\t"; //print
    cout << i_assignments << endl;
}

//merge
void merge(int B[], int C[], int n, int A[], int& comparisons){
    int i = 0; //initalize to zero
    int j = 0;
    int k = 0;
    int p = n/2; //p is half of array size for B
    int q = n-p; //remaining elements are for C
    while(i < p && j < q){
        comparisons++; //comparision add for if
        if(B[i] < C[j]){ //if value at B is smaller then C, place first
            A[k] = B[i]; 
            k++;
            i++;
            
        }
        else{ //or else place C first
            A[k] = C[j];
            k++;
            j++;
        }
    }
    if(i == p){ //when B is done
        while (j < q) { //put last Cs as needed
            A[k] = C[j];
            j++; //next values in each array
            k++;
        }
    }
    else{ //if C is done
        while (i < p) { //place last Bs as needed
            A[k] = B[i];
            i++;
            k++;
        }
    }
}

//merge sort
int merge_sort(int A[], int n){
    int halfSize = n/2; 
    int B[halfSize]; //A is split among B and C
    int C[n - halfSize];
    if(n > 1){
        for(int i = 0; i < halfSize; i++){ //half of A is in B
            B[i] = A[i];
        }
        for(int j = halfSize; j < n; j++){ //A's other half
            C[j - halfSize] = A[j];
        }
        merge_sort(B, halfSize); //recursive calls to keep splitting
        merge_sort(C, n - halfSize);
        merge(B, C, n, A,  m_comparisons); //merge
    }
    return m_comparisons;
}

//main
int main (){
    int n;
    int array[100000]; //array to sort (set to a high value to avoid having to add additional libraries)
    int b_array[100000];
    int s_array[100000];
    int i_array[100000];
    int m_array[100000];
    cin >> n; //N positive integers will follow
    for(int i = 0; i < n; i++){
        cin >> array[i]; //array nums input
    }

    copy(array, b_array, n); //make copies to keep unsorted array
    copy(array, s_array, n); //make copies to keep unsorted array
    copy(array, i_array, n); //make copies to keep unsorted array
    copy(array, m_array, n); //make copies to keep unsorted array

    bubble_sort(b_array, n);//print key comparisons + array swaps
    selection_sort(s_array, n); //print key comparisons + array swaps
    insertion_sort(i_array, n); //print key comparisons + array assignments
    cout << merge_sort(m_array, n) << endl; //print key comparisons

    return 0;
}

