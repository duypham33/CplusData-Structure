
#include <iostream>
#include <vector>
#include <math.h>
#include<stack>
#include<queue>
#include <string>
#include <sstream>     //Neccessary to use stringstream

using std::cout;
using std::endl;
using std::string;
using std::vector;

//Array
int findMaxConsecutiveOnes(std::vector<int>& nums);

int findNumbers(std::vector<int>& nums);

std::vector<int> sortedSquares(std::vector<int>& nums);


////Best Memory Distribution
//class MyLinkedList {
//public:
//    /** Initialize your data structure here. */
//    std::vector<int> linkedList;
//
//    MyLinkedList() {
//
//    }
//
//    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
//    int get(int index) {
//
//        // cout << linkedList.size();
//        if (index < linkedList.size())
//            return linkedList[index];
//        return -1;
//    }
//
//    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
//    void addAtHead(int val) {
//
//        linkedList.insert(linkedList.begin(), val);
//    }
//
//    /** Append a node of value val to the last element of the linked list. */
//    void addAtTail(int val) {
//
//        linkedList.push_back(val);
//    }
//
//    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
//    void addAtIndex(int index, int val) {
//
//        if (index <= linkedList.size())
//            linkedList.insert(linkedList.begin() + index, val);
//
//        // cout << linkedList[index];
//    }
//
//    /** Delete the index-th node in the linked list, if the index is valid. */
//    void deleteAtIndex(int index) {
//
//        if (index < linkedList.size())
//            linkedList.erase(linkedList.begin() + index);
//    }
//};
//
//
//
//
////Best Runtime Distribution
//struct SinglyListNode {
//    int val;
//    SinglyListNode* next;
//    SinglyListNode(int x) : val(x), next(NULL) {}
//};
//class MyLinkedList {
//public:
//    /** Initialize your data structure here. */
//    MyLinkedList() {
//        head = NULL;
//        tail = NULL;
//    }
//
//    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
//    int get(int index) {
//        if (head == NULL) {
//            return -1;
//        }
//        if (index == 0) {
//            return head->val;
//        }
//        SinglyListNode* current = head;
//        int currentIndex = 0;
//
//        while (currentIndex != index) {
//            currentIndex++;
//            current = current->next;
//            if (current == NULL) {
//                break;
//            }
//            if (currentIndex == index) {
//                return current->val;
//            }
//        }
//
//        return -1;
//    }
//
//    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
//    void addAtHead(int value) {
//        SinglyListNode* node = (struct SinglyListNode*)malloc(sizeof(struct SinglyListNode));
//        node->val = value;
//        node->next = NULL;
//        if (head == NULL) {
//            this->head = node;
//            this->tail = node;
//        }
//        else {
//            node->next = this->head;
//            this->head = node;
//        }
//    }
//
//    /** Append a node of value val to the last element of the linked list. */
//    void addAtTail(int val) {
//        SinglyListNode* node = (struct SinglyListNode*)malloc(sizeof(struct SinglyListNode));
//        node->val = val;
//        node->next = NULL;
//        SinglyListNode* current = head;
//        if (head == NULL) {
//            this->head = node;
//            this->tail = node;
//        }
//        else {
//            this->tail->next = node;
//            this->tail = this->tail->next;
//        }
//    }
//
//    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
//    void addAtIndex(int index, int value) {
//        SinglyListNode* node = (struct SinglyListNode*)malloc(sizeof(struct SinglyListNode));
//        node->val = value;
//        node->next = NULL;
//        if (index == 0) {
//            this->addAtHead(value);
//            return;
//        }
//        SinglyListNode* current = head;
//        int currentIndex = 0;
//        while (currentIndex != index) {
//            if (currentIndex == index - 1) {
//                node->next = current->next;
//                if (current->next == NULL) {
//                    tail = node;
//                }
//                current->next = node;
//                break;
//            }
//            currentIndex++;
//            current = current->next;
//            if (current == NULL)
//                break;
//        }
//    }
//
//    /** Delete the index-th node in the linked list, if the index is valid. */
//    void deleteAtIndex(int index) {
//        SinglyListNode* current = head;
//        int currentIndex = 0;
//        if (index == 0) {
//            if (head == NULL)
//                return;
//            head = head->next;
//            return;
//        }
//        while (index != currentIndex) {
//            if (currentIndex == index - 1) {
//                if (current->next == NULL) {
//                    break;
//                }
//                if (current->next->next == NULL) {
//                    current->next = NULL;
//                    tail = current;
//                }
//                else {
//                    SinglyListNode* currentNext = current->next;
//                    current->next = currentNext->next;
//                    currentNext->next = NULL;
//                }
//                break;
//            }
//            currentIndex++;
//            current = current->next;
//            if (current == NULL) {
//                break;
//            }
//        }
//    }
//private:
//    SinglyListNode* head, * tail;
//};

//Linked List
struct Node
{
    int val;
    Node* pNext;
    Node(const int& newVal = 0) : val(newVal), pNext(NULL) {}
};


class MyLinkedList 
{
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        this->pHead = NULL;
    }

    //Getter
    Node* getHeadPtr()
    {
        return pHead;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0)
            return -1;
        else
        {
            Node* pCur = this->pHead;
            int count = 0;

            while (pCur != NULL && count != index)
            {
                pCur = pCur->pNext;
                count++;
            }

            if (pCur == NULL)
                return -1;
            else
                return pCur->val;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node* pMem = new Node(val);
        if (pMem != NULL)
        {
            pMem->pNext = this->pHead;
            this->pHead = pMem;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node* pMem = new Node(val);
        if (this->pHead == NULL)
        {
            pMem->pNext = this->pHead;
            this->pHead = pMem;
        }
        else
        {
            Node* pCur = this->pHead;
            while (pCur->pNext != NULL)
            {
                pCur = pCur->pNext;
            }

            pCur->pNext = pMem;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (this->pHead == NULL)
        {
            if (index == 0)
                addAtHead(val);
        }

        else
        {
            if (index == 0)   //Insert at front
                addAtHead(val);

            else
            {
                Node* pCur = this->pHead;
                for (int i = 0; i < index - 1; i++)
                {
                    if (pCur == NULL)
                        break;
                    pCur = pCur->pNext;
                }

                if (index > 0 && pCur != NULL)
                {
                    Node* pMem = new Node(val);
                    pMem->pNext = pCur->pNext;
                    pCur->pNext = pMem;
                }
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (this->pHead == NULL || (this->pHead != NULL && index == 0))   //Delete at front
        {
            if (index == 0)  //Delete at front
            {
                Node* pFront = this->pHead;
                this->pHead = this->pHead->pNext;
                delete pFront;
            }
        }

        else  //this->pHead != NULL && index != 0
        {
            Node* pCur = this->pHead;
            for (int i = 0; i < index - 1; i++)
            {
                if (pCur == NULL)
                    break;
                pCur = pCur->pNext;
            }

            if (index > 0 && pCur != NULL)
            {
                //Delete the node after pCur
                if (pCur->pNext != NULL)
                {
                    Node* pTemp = pCur->pNext;
                    pCur->pNext = pTemp->pNext;
                    delete pTemp;
                }
            }
        }
    }

private:
    Node* pHead;
};


//Print list
void printList(Node* pHead);

Node* reverseList(Node* pHead);


class Solution 
{
public:
    Node* mergeTwoLists(Node* l1, Node* l2) 
    {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val <= l2->val) 
        {
            l1->pNext = mergeTwoLists(l1->pNext, l2);
            return l1;
        }
        else 
        {
            l2->pNext = mergeTwoLists(l1, l2->pNext);
            return l2;
        }
    }
};



//Binary Tree
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int newVal) : val(newVal), left(NULL), right(NULL) {}
    TreeNode(int newVal, TreeNode* leftNode, TreeNode* rightNode) : val(newVal), left(leftNode), right(rightNode) {}
};

class traversalSolution
{
public:
    std::vector<int> iterPostTraversal(TreeNode* root)
    {
        std::vector<int> nodeList;
        std::stack<TreeNode*> s;

        int flag = 1;
        if (root != NULL)
        {
            TreeNode* pCur = root;
            while (!s.empty() || pCur)
            {
                while (pCur && flag == 1)
                {
                    s.push(pCur);
                    pCur = pCur->left;
                }
                if (s.top()->right && flag == 1)
                    pCur = s.top()->right;
                else
                {
                    pCur = s.top();
                    s.pop();
                    nodeList.push_back(pCur->val);

                    if (!s.empty())
                    {
                        if (pCur == s.top()->left && s.top()->right != NULL)
                        {
                            pCur = s.top()->right;
                            flag = 1;
                        }

                        else       // (pCur == s.top()->left && s.top()->right == NULL) ||  pCur == s.top()->right
                            flag = 0;
                    }

                    else
                        pCur = NULL;
                }
            }
        }

        return nodeList;
    }


    void recsInoderTraversal(TreeNode* root, std::vector<int>& nodeList)
    {
        if (root)
        {
            recsInoderTraversal(root->left, nodeList);
            nodeList.push_back(root->val);
            recsInoderTraversal(root->right, nodeList);
        }
    }


    std::vector<std::vector<int>> levelOrderTraversal(TreeNode* root)
    {
        std::vector<std::vector<int>> levelList;
        std::queue<TreeNode*> q;

        if (root)
        {
            int level = 1;
            q.push(root);
            int curN = 1, newN = 0;

            while (!q.empty())
            {
                levelList.push_back({});
                while (curN > 0)
                {
                    TreeNode* pCur = q.front();
                    if (pCur->left)
                    {
                        q.push(pCur->left);
                        newN++;
                    }
                    if (pCur->right)
                    {
                        q.push(pCur->right);
                        newN++;
                    }

                    q.pop();
                    curN--;
                    levelList[level - 1].push_back(pCur->val);
                }

                curN = newN;
                newN = 0;
                level++;
            }
        }

        return levelList;
    }


    int maxDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        int leftMaxDepth = maxDepth(root->left);
        int rightMaxDepth = maxDepth(root->right);

        return (leftMaxDepth > rightMaxDepth) ? leftMaxDepth + 1 : rightMaxDepth + 1;
    }

};



class symmetricSolution
{
public:
    // Check symmetric structure of tree, not including values of nodes

    //Top-down
    void isReflective(TreeNode* leftNode, TreeNode* rightNode, bool& check)
    {
        //Top-down method
        if (check == false)
            return;
        if (!leftNode->left && !leftNode->right && !rightNode->left && !rightNode->right)
        {
            check = true;
            return;
        }


        if ((leftNode->left && !rightNode->right) || (!leftNode->left && rightNode->right) ||
            (leftNode->right && !rightNode->left) || (!leftNode->right && rightNode->left))
        {
            check = false;
            return;
        }


        if (leftNode->left && rightNode->right)
            isReflective(leftNode->left, rightNode->right, check);
        if (leftNode->right && rightNode->left)
            isReflective(leftNode->right, rightNode->left, check);
    }




    //Bottom-up
    bool isReflective2(TreeNode* leftNode, TreeNode* rightNode)
    {
        if (!leftNode && !rightNode)
            return true;
        if (!leftNode || !rightNode)
            return false;

        return (isReflective2(leftNode->left, rightNode->right) && isReflective2(leftNode->right, rightNode->left));
    }




    bool isSymmetric(TreeNode* root)
    {
        if (!root)
            return true;

        bool check = true;
        if ((root->left && !root->right) || (!root->left && root->right))
            check = false;
        else if (root->left && root->right)
            isReflective(root->left, root->right, check);

        return check;
    }




    // Check symmetric structure of tree, including values of nodes

    //Top-down
    void isTotallyReflective(TreeNode* leftNode, TreeNode* rightNode, bool& check)
    {
        //Top-down method
        if (leftNode->val != rightNode->val)
            check = false;

        if (check == false)
            return;
        if (!leftNode->left && !leftNode->right && !rightNode->left && !rightNode->right)
        {
            check = true;
            return;
        }


        if ((leftNode->left && !rightNode->right) || (!leftNode->left && rightNode->right) ||
            (leftNode->right && !rightNode->left) || (!leftNode->right && rightNode->left))
        {
            check = false;
            return;
        }


        if (leftNode->left && rightNode->right)
            isTotallyReflective(leftNode->left, rightNode->right, check);
        if (leftNode->right && rightNode->left)
            isTotallyReflective(leftNode->right, rightNode->left, check);
    }



    //Bottom-up
    bool isTotallyReflective2(TreeNode* leftNode, TreeNode* rightNode)
    {
        if (!leftNode && !rightNode)
            return true;
        if (!leftNode || !rightNode)
            return false;
        if (leftNode->val == rightNode->val)
            return (isReflective2(leftNode->left, rightNode->right) && isReflective2(leftNode->right, rightNode->left));

        return false;
    }



    bool isTotallySymmetric(TreeNode* root)
    {
        if (!root)
            return true;

        bool check = true;
        if ((root->left && !root->right) || (!root->left && root->right))
            check = false;
        else if (root->left && root->right)
            isTotallyReflective(root->left, root->right, check);

        return check;
    }


    // Solve iteratively, which is helpful to prevent stack overflow
    bool isSymmetricIter(TreeNode* root)
    {
        //We can solve with two queues for leftsub and rightsub. Howver, one queue is enough
        std::queue<TreeNode*> q;

        if (!root)
            return true;

        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode* l = q.front();
            q.pop();
            TreeNode* r = q.front();
            q.pop();

            if ((!l && r) || (l && !r))
                return false;

            if (!l && !r)
                continue;

            if (l->val != r->val)
                return false;

            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }

        return true;
    }

};


class buildTree_fromTraversal
{
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
    {
        if (inorder.empty())
            return NULL;
        else
        {
            int rootVal = postorder.back();
            TreeNode* root = new TreeNode(rootVal);

            //Find the index of root->val in the inorder traversal
            auto root_index = std::find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();

            std::vector<int> subleft_Inorder = { inorder.begin(), inorder.begin() + root_index },
                subright_Inorder = { inorder.begin() + root_index + 1, inorder.end() };

            std::vector<int> subleft_Postorder = { postorder.begin(), postorder.begin() + root_index },
                subright_Postorder = { postorder.begin() + root_index, postorder.end() - 1 };

            root->left = buildTree(subleft_Inorder, subleft_Postorder);

            root->right = buildTree(subright_Inorder, subright_Postorder);

            return root;
        }
    }


    TreeNode* buildTreeIter(std::vector<int>& inorder, std::vector<int>& postorder)
    {
        if (postorder.empty())
            return NULL;
        else
        {
            std::stack<TreeNode*> s;
            TreeNode* pTemp = NULL;

            int inIndex = 0, postIndex = 0;
            int n = inorder.size();
            while (postIndex < n)
            {
                if (inIndex < n && inorder[inIndex] == postorder[postIndex])
                {
                    pTemp = new TreeNode(postorder[postIndex], pTemp, nullptr);
                    inIndex++;
                    postIndex++;
                }

                else
                {
                    if (!s.empty() && s.top()->val == postorder[postIndex])
                    {
                        s.top()->right = pTemp;
                        pTemp = s.top();
                        s.pop();
                        postIndex++;
                    }
                    else
                    {
                        s.push(new TreeNode(inorder[inIndex], pTemp, nullptr));
                        inIndex++;
                        pTemp = NULL;
                    }
                }
            }

            return pTemp;
        }
    }



    TreeNode* buildTree_fromPreIn(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        if (inorder.empty())
            return NULL;

        int n = inorder.size() - 1;
        int preStart = 0;
        return ultiBuild_fromPreIn(preorder, inorder, 0, n, preStart);
    }

    TreeNode* ultiBuild_fromPreIn(std::vector<int>& preorder, std::vector<int>& inorder, int start, int end, int& preStart)
    {
        if (start > end)
            return NULL;

        int value = preorder[preStart];
        preStart++;
        TreeNode* node = new TreeNode(value);
        if (start == end)
            return node;
        else
        {
            auto pos = std::find(inorder.begin() + start, inorder.begin() + end + 1, value) - inorder.begin();
            node->left = ultiBuild_fromPreIn(preorder, inorder, start, pos - 1, preStart);
            node->right = ultiBuild_fromPreIn(preorder, inorder, pos + 1, end, preStart);

            return node;
        }
    }


    TreeNode* buildTreeIter_fromPreIn(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        if (preorder.empty())
            return NULL;
        else
        {
            int size = inorder.size();
            int preIndex = 0, inIndex = 0;
            int flag = 0;    // 0 is for left, 1 is for right
            std::stack<TreeNode*> s;
            TreeNode* pRoot = new TreeNode(preorder[0]);   //To return pRoot at the end
            TreeNode* pTemp = NULL;

            while (inIndex < size)
            {
                if (!s.empty() && inorder[inIndex] == s.top()->val)
                {
                    pTemp = s.top();
                    s.pop();
                    flag = 1;
                    inIndex++;
                }

                else if (preIndex < size)
                {
                    if (!pTemp)
                        pTemp = pRoot;
                    else
                    {
                        TreeNode* pMem = new TreeNode(preorder[preIndex]);
                        if(flag == 0)
                            pTemp->left = pMem;
                        else
                            pTemp->right = pMem;

                        pTemp = pMem;
                    }

                    if (preorder[preIndex] == inorder[inIndex])
                    {
                        flag = 1;
                        preIndex++;
                        inIndex++;
                    }
                    else
                    {
                        s.push(pTemp);
                        flag = 0;
                        preIndex++;
                    }
                }

                else
                    inIndex++;
            }

            return pRoot;
        }
    }

};


class Codec    //By level order
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string code = "";
        if (root)
        {
            std::queue<TreeNode*> q;         
            q.push(root);
            code += std::to_string(root->val);

            while (!q.empty())
            {
                TreeNode* pCur = q.front();
                if (pCur->left)
                {
                    code = code + "," + std::to_string(pCur->left->val);
                    q.push(pCur->left);
                }
                else
                    code = code + ",null";

                if (pCur->right)
                {
                    code = code + "," + std::to_string(pCur->right->val);
                    q.push(pCur->right);
                }
                else
                    code = code + ",null";

                q.pop();
            }

            //Clear all "null" at the end of the string      
            while (code.back() == 'l')
            {
               //To delete ",null" at the end, we wont use erase() function, since it costs O(N) at once. Instead, we use pop_back(), that costs O(1)
                for (int i = 0; i < 5; i++)
                {
                    code.pop_back();
                }
            }
        }

        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        TreeNode* root = NULL;
        if (data != "")
        {
            size_t pos = data.find(",");
            if (pos == string::npos)
                return  new TreeNode(atoi(data.c_str()));

            root = new TreeNode(atoi(data.substr(0, pos).c_str()));
            TreeNode* pCur = root;
            data.erase(0, pos + 1);
            std::queue<TreeNode*> q;
            q.push(pCur);

            while (!q.empty())
            {
                pCur = q.front();
                q.pop();
                //Left
                if (data == "")
                    break;
                pos = data.find(",");
                if (pos == string::npos)
                {
                    pCur->left = new TreeNode(atoi(data.c_str()));
                    break;
                }

                string subS = data.substr(0, pos);
                if (subS != "null")
                {
                    pCur->left = new TreeNode(atoi(subS.c_str()));
                    q.push(pCur->left);
                }
                data.erase(0, pos + 1);

                //Right
                if (data == "")
                    break;
                pos = data.find(",");
                if (pos == string::npos)
                {
                    pCur->right = new TreeNode(atoi(data.c_str()));
                    break;
                }

                subS = data.substr(0, pos);
                if (subS != "null")
                {
                    pCur->right = new TreeNode(atoi(subS.c_str()));
                    q.push(pCur->right);
                }
                data.erase(0, pos + 1);
            }
        }

        return root;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize2(string data)
    {
        if (data.length() == 0)
            return NULL;

        std::stringstream ss(data);    //Stringstream is efficient to parse a string 
        string val;
        std::getline(ss, val, ',');    //If ',' does not exist, val = data
        TreeNode* root = new TreeNode(atoi(val.c_str()));
        TreeNode* cur = root;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            std::getline(ss, val, ',');
            if (val != "null")
            {
                cur->left = new TreeNode(atoi(val.c_str()));
                q.push(cur->left);
            }

            std::getline(ss, val, ',');
            if (val != "null")
            {
                cur->right = new TreeNode(atoi(val.c_str()));
                q.push(cur->right);
            }
        }

        return root;
    }
};



//Sort Algorithms
class Sort
{
public:
    //Selection Sort
    static vector<int> selectionSort(vector<int>& arr)
    {
        int size = arr.size();
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[i])
                {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }

        return arr;
    }


    //Merge Sort
    static void mergeSort(vector<int>& arr, int l, int r)
    {
        if (l == r)
            return;

        int mid = l + (r - l) / 2;     // r - l, avoid overflow
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        //Merge two sorted sub-arrays into one array
        vector<int> subLeft = {arr.begin() + l, arr.begin() + mid + 1};
        int size = mid - l + 1;
        int cur1 = 0, cur2 = mid + 1;
        for (int i = l; i <= r; i++)
        {
            if (cur1 >= size)
                break;
            if (cur2 < r + 1 && arr[cur2] < subLeft[cur1])
                arr[i] = arr[cur2++];
            else
                arr[i] = subLeft[cur1++];
        }

        subLeft.clear();
    }

    static void mergeSort(vector<int>& arr)
    {
        int size = arr.size();
        if (size < 2)
            return;
        else
            mergeSort(arr, 0, size - 1);
    }

};


