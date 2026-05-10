/* 
 * Book Allocation Problem
 * 
 * There are N books, each ith book has A[i] number of pages.
 * 
 * You have to allocate books to M number of students so that the MAXIMUM number of pages allocated 
 * to a student is minimum.
 * 
 *  - Each book should be allocated to a student.
 *  - Each student has to be allocated at least one book.
 *  - Allotment should be in contiguous order.
 * 
 * Calculate and return that minimum possible number.
 * 
 * Return -1 if a valid assignment is not possible.
 * 
 * variation : how much memory to be allocated to each process so that the max allotted memory to a process is minimum.
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 bool isValid (vector<int> &books, int m, int n, int maxNumberOfPages)
 {
    int stuCount = 1, pages = 0;
    for(int i=0; i<n; i++)
    {
        if (pages + books[i] <= maxNumberOfPages)
        {
            pages += books[i];
        }
        else
        {
            stuCount++;
            pages = books[i];
        }
    }
    
    return stuCount < m ? true : false;
 }

 int maxPages(vector<int> &books, int m, int n)
 {
    if (m > n)
    {
        return -1;
    }
    
    int start = 0, end = 0;
    int mid = 0, ans = -1;

    for (int &ele:books)
    {
        end += ele;
    }

    while (start <= end)
    {
        int mid = start + (end-start) / 2;

        if (isValid(books, m, n, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
 }

 int main()
 {
    int N,M;

    cout << "Enter total no. of books : " << endl;
    cin >> N;

    vector<int> books(N);

    cout << "Enter total no. of pages for each books : " << endl;
    for (int &ele : books)
    {
        cin >> ele;
    }

    cout << "Enter the number of students : " << endl;
    cin >> M;

    int ans = maxPages(books ,M, N);
    cout << "the MAXIMUM number of pages allocated to a student that should be minimum is: " << ans;
 }