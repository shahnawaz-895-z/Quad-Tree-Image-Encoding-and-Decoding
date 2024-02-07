#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include <cstdlib>
#include <ctime>
#include<iostream>
#include<queue>
using namespace std;
using namespace cv;



class node1 {
public:
    string colour;
    int color;
    node1* tl;
    node1* tr;
    node1* bl;
    node1* br;
    int srow;
    int erow;
    int scol;
    int ecol;
    string front() {
        if (color == 127) {
            return "grey";
        }
        else if (color == 0) {
            return "white";
        }
        else if (color == 255) {
            return "black";
        }
        else {
            return "unknown";
        }
    }


};


void qd(node1* root, int** array)
{

    if (root->colour == "white" || root->colour == "black" || root->srow + 1 == root->erow || root->scol + 1 == root->ecol) {
        return;
    }


    bool white = false;
    bool black = false;
    int mid_row = (root->srow + root->erow) / 2;
    int mid_col = (root->scol + root->ecol) / 2;
    for (int i = root->srow; i < mid_row; i++)
    {
        for (int j = root->scol; j < mid_col; j++)
        {
            if (array[i][j] == 0)
            {
                white = true;
            }
            if (array[i][j] == 255)
            {
                black = true;
            }
        }
    }
    root->tl = new node1;
    if (white == true && black == true)
    {
        root->tl->colour = "grey";
        root->tl->color = 127;


    }
    if (white && black == false)
    {
        root->tl->colour = "white";
        root->tl->color = 0;
    }
    if (white == false && black)
    {
        root->tl->colour = "black";
        root->tl->color = 255;
    }
    root->tl->srow = root->srow;
    root->tl->erow = mid_row;
    root->tl->scol = root->scol;
    root->tl->ecol = mid_col;

    white = false;
    black = false;

    //for topriht 

    for (int i = root->srow; i < mid_row; i++)
    {
        for (int j = mid_col; j < root->ecol; j++)
        {
            if (array[i][j] == 0)
            {
                white = true;
            }
            if (array[i][j] == 255)
            {
                black = true;
            }
        }
    }
    root->tr = new node1;
    if (white == true && black == true)
    {
        root->tr->colour = "grey";
        root->tr->color = 127;

    }
    if (white && black == false)
    {
        root->tr->colour = "white";
        root->tr->color = 0;
    }
    if (white == false && black)
    {
        root->tr->colour = "black";
        root->tr->color = 255;
    }
    root->tr->srow = root->srow;
    root->tr->erow = mid_row;
    root->tr->scol = mid_col;
    root->tr->ecol = root->ecol;

    white = false;
    black = false;

    //for  bottom left

    for (int i = mid_row; i < root->erow; i++)
    {
        for (int j = root->scol; j < mid_col; j++)
        {
            if (array[i][j] == 0)
            {
                white = true;
            }
            if (array[i][j] == 255)
            {
                black = true;
            }
        }
    }
    root->bl = new node1;
    if (white == true && black == true)
    {
        root->bl->colour = "grey";
        root->bl->color = 127;

    }
    if (white && black == false)
    {
        root->bl->colour = "white";
        root->bl->color = 0;
    }
    if (white == false && black)
    {
        root->bl->colour = "black";
        root->bl->color = 255;
    }
    root->bl->srow = mid_row;
    root->bl->erow = root->erow;
    root->bl->scol = root->scol;
    root->bl->ecol = mid_col;

    white = false;
    black = false;
    //for right bottom

    for (int i = mid_row; i < root->erow; i++)
    {
        for (int j = mid_col; j < root->ecol; j++)
        {
            if (array[i][j] == 0)
            {
                white = true;
            }
            if (array[i][j] == 255)
            {
                black = true;
            }
        }
    }
    root->br = new node1;
    if (white == true && black == true)
    {
        root->br->colour = "grey";
        root->br->color = 127;
    }
    if (white && black == false)
    {
        root->br->colour = "white";
        root->br->color = 0;
    }
    if (white == false && black)
    {
        root->br->color = 255;
        root->br->colour = "black";
    }
    root->br->srow = mid_row;
    root->br->erow = root->erow;
    root->br->scol = mid_col;
    root->br->ecol = root->ecol;

    qd(root->tl, array);
    qd(root->tr, array);
    qd(root->bl, array);
    qd(root->br, array);

}

void levelOrderTraversal(node1* root) {
    if (root == nullptr) return;
    queue<node1*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            node1* currNode = q.front();
            q.pop();
            if (currNode->color == 127) {
                cout << "grey";
            }
            else if (currNode->color == 0) {
                cout << "white";
            }
            else if (currNode->color == 255) {
                cout << "black";
            }
            cout << " ";
            if (currNode->tl) q.push(currNode->tl);
            if (currNode->tr) q.push(currNode->tr);
            if (currNode->bl) q.push(currNode->bl);
            if (currNode->br) q.push(currNode->br);
        }
        cout << endl;
    }
}

void quadtreeToArray(node1* root, int** quadtreeArray, int rar) {
    // Initialize the array with a default value (e.g., -1):
    int ARRAY_SIZE = rar;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            quadtreeArray[i][j] = -1;
        }
    }

    // Define a queue to traverse the quadtree in level order:
    queue<node1*> q;

    // Start with the root node:
    q.push(root);

    // Traverse the quadtree in level order:
    while (!q.empty()) {
        // Get the number of nodes at the current level:
        int levelSize = q.size();

        // Process each node at the current level:
        for (int i = 0; i < levelSize; i++) {
            // Get the next node from the queue:
            node1* currNode = q.front();
            q.pop();

            // Compute the size of the quadrant represented by this node:
            int quadSize = (currNode->erow - currNode->srow);

            // Compute the row and column indices of the top-left corner of the quadrant:
            int rowIdx = currNode->srow;
            int colIdx = currNode->scol;

            // Fill in the corresponding elements of the 2D array with the node's color:
            for (int r = 0; r < quadSize; r++) {
                for (int c = 0; c < quadSize; c++) {
                    quadtreeArray[rowIdx + r][colIdx + c] = currNode->color;
                }
            }

            // Add the node's children to the queue (if they exist):
            if (currNode->tl) q.push(currNode->tl);
            if (currNode->tr) q.push(currNode->tr);
            if (currNode->bl) q.push(currNode->bl);
            if (currNode->br) q.push(currNode->br);
        }
    }
}

class node {
public:
    int data;
    node* next;
    node* down;

    node(int val) {
        data = val;
        next = NULL;
        down = NULL;
    }
};

class LinkedList {
public:
    node* head;

    LinkedList() {
        head = NULL;
    }
    void insert(int val, int row) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = newNode;
        }
        else {
            int i = 0;
            node* temp = head;
            while (i < row) {
                if (temp->down == NULL) {
                    temp->down = newNode;
                    return;
                }
                temp = temp->down;
                i++;
            }
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() {
        node* currentRow = head;

        while (currentRow) {
            node* currentCol = currentRow;

            while (currentCol) {
                cout << currentCol->data << " ";
                currentCol = currentCol->next;
            }

            cout << endl;
            currentRow = currentRow->down;
        }
    }
};

void convertTo2dLL(int** array, int row, int col) {
    LinkedList ll;
    int count = 0;
    int range = 0;
    int range1 = 0;
    int x = 0;

    // Insert the values into the linked list row-wise
    for (int i = 0; i < row; i++) {
        node* rowHead = NULL;
        node* currentRow = NULL;
        range = 0;
        x = 0;

        for (int j = 0; j < col; j++) {

            node* newnode = new node(array[i][j]);
            if (rowHead == NULL) {
                rowHead = newnode;
                currentRow = newnode;
            }
            else {
                currentRow->next = newnode;
                currentRow = currentRow->next;
            }

            if (j == 0) {
                count++;
                ll.insert(count, i + 1);
            }
            else {
                range++;
                if (array[i][j] == 0)
                {

                    ll.insert(range, i);
                    while (array[i][j] == 0 && j < col)
                    {
                        j++;
                        if (array[i][j] == 225)
                        {
                            /* range1 = range;*/
                            while (array[i][j] != 225 && j < col)
                            {
                                range++;
                                j++;
                                /*if (j == col) {
                                    x = 1;
                                    ll.insert(-2, i);
                                }
                            */
                            }

                        }

                        range++;
                    }
                    ll.insert(range, i);


                }



                if (ll.head == NULL) {
                    ll.head = rowHead;
                }





            }
        }
        ll.insert(-2, i);
        range1 = -1;
        for (int k = 0;k < col;k++)
        {
            node* newnode = new node(array[i][k]);
            if (rowHead == NULL) {
                rowHead = newnode;
                currentRow = newnode;
            }
            // for the black colour


            range1++;
            if (array[i][k] == 255)

            {



                ll.insert(range1, i);
                while (array[i][k] == 255 && k < col)
                {
                    k++;
                    if (array[i][k] == 0)
                    {
                        while (array[i][k] != 0 && k < col)
                        {
                            range1++;
                            k++;
                            /*if (k == col) {
                                x = 1;
                                ll.insert(-1, i);
                            }
                        */
                        }

                    }
                    /*if (j == col) {
                        {
                            if (x != 1)
                            {

                                x = 1;
                                ll.insert(-2, i);
                            }
                        }
                    }
                    */
                    range1++;
                }

                ll.insert(range1, i);
                /*if (k == col)
                    {
                        if (x != 1)
                        {

                            x = 1;
                            ll.insert(-1, i);
                        }
                    }*/
            }
        }
        if (ll.head == NULL) {
            ll.head = rowHead;

        }
        ll.insert(-1, i);


    }

    // Print the linked list
    ll.print();
}



int main()
{
    /*
    cv::Mat img = cv::imread("C:/Users/DELL/Desktop/Test_Images (1)/Student Test Images");
     */
     /* namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
      cv::imshow("First OpenCV Application", img);
      cv::moveWindow("First OpenCV Application", 0, 45);
      cv::waitKey(0);\
      cv::destroyAllWindows();*/


      // Load an image from file    😂😂

    Mat img = imread("C:/Users/DELL/Desktop/t1.bmp");

    // Check if the image was loaded successfully


      /*  namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
        imshow("First OpenCV Application", img);
        moveWindow("First OpenCV Application", 0, 45);
        waitKey(0);
        destroyAllWindows();*/


    int row = img.rows;
    int col = img.cols;
    /*int row = 30;
    int col = 30;*/
    srand(time(NULL));

    // Generate a random number between 1 and 2
    int random = 0;

    int** array = new int* [row];
    for (int i = 0; i < row; i++)
    {
        array[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            random = rand() % 2 + 1;
            /*if (random == 1)
            {
                array[i][j] = 0;
            }
            else array[i][j] = 225;*/
            array[i][j] = img.at<uchar>(i, j * 3);
            //  cout << array[i][j]<<" ";
        }
        // cout << endl;
    }
    cout << endl;
    cout << "number of rows " << row << "\nnumber of coloms " << col << endl;


    // Print the two-dimensional linked list
    convertTo2dLL(array, row, col);

    node1* root = new node1;
    root->colour = "grey";
    root->srow = 0;
    root->erow = img.rows;
    root->scol = 0;
    root->ecol = img.cols;

    qd(root, array);

    int ARRAY_SIZE = row;

    levelOrderTraversal(root);


    // int quadtreeArray[ARRAY_SIZE][ARRAY_SIZE];
    int** quadtreeArray = new int* [row];
    for (int i = 0; i < row; i++)
    {
        quadtreeArray[i] = new int[col];
    }
    quadtreeToArray(root, quadtreeArray, row);
    // Free memory allocated for array

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            img.at<uint8_t>(i, j) = quadtreeArray[i][j];
        }

    }
    imshow("Image After Storing", img);

    // Wait for a key press
    cv::waitKey(0);

    cout << endl;
    cout << "number of rows " << row << "\nnumber of coloms " << col << endl;
    float sum = 0;

    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < col;j++)
        {

            sum += ((array[i][j] - quadtreeArray[i][j]) * (array[i][j] - quadtreeArray[i][j]));
        }
    }
    float x = (sum / (row * col));
    float y = 0;
    y = (100 * (1 - (x / (255 * 255))));
    cout << "Accuracy rate  " << y;
    // Destroy the window
    //cv::destroyWindow("Image After Storing");
    for (int i = 0; i < row; i++) {
        delete[] array[i];
    }
    delete[] array;




    return 0;
}