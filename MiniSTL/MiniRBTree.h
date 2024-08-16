//#include <iostream>
//#include <sstream>
//#include <string>
//
//enum class Color { RED, BLACK };
//
//template <typename Key, typename Value> class RedBlackTree {
//    class Node {
//    public:
//        Key key;
//        Value value;
//        Color color;
//        Node* left;
//        Node* right;
//        Node* parent;
//
//        // ���캯��
//        Node(const Key& k, const Value& v, Color c, Node* p = nullptr)
//            : key(k), value(v), color(c), left(nullptr), right(nullptr), parent(p) {
//        }
//        Node()
//            : color(Color::BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
//    };
//
//private:
//    Node* root;
//    size_t size;
//    Node* Nil;
//
//    // ��ѯĳ�ڵ�
//    Node* lookUp(Key key) {
//        Node* cmpNode = root;
//
//        while (cmpNode) {
//            if (key < cmpNode->key) {
//                cmpNode = cmpNode->left;
//            }
//            else if (key > cmpNode->key) {
//                cmpNode = cmpNode->right;
//            }
//            else {
//                return cmpNode;
//            }
//        }
//        return cmpNode;
//    }
//
//    // ��������
//    void rightRotate(Node* node) {
//        Node* l_son = node->left; // ��ȡ��ǰ�ڵ�����ӽڵ�
//
//        // ��ǰ�ڵ��������������ӽڵ��������
//        node->left = l_son->right;
//        // ������ӽڵ���������ǿգ������丸ָ��
//        if (l_son->right) {
//            l_son->right->parent = node;
//        }
//
//        // ���ӽڵ���Ϊ��ǰ�ڵ�λ�ã��������ڵ��ϵ
//        l_son->parent = node->parent;
//        // �����ǰ�ڵ��Ǹ��ڵ㣬���¸��ڵ�Ϊ���ӽڵ�
//        if (!node->parent) {
//            root = l_son;
//            // �����ǰ�ڵ����丸�ڵ�����ӽڵ㣬���¸��ڵ�����ӽڵ�Ϊ���ӽڵ�
//        }
//        else if (node == node->parent->left) {
//            node->parent->left = l_son;
//            // �����ǰ�ڵ����丸�ڵ�����ӽڵ㣬���¸��ڵ�����ӽڵ�Ϊ���ӽڵ�
//        }
//        else {
//            node->parent->right = l_son;
//        }
//
//        // �������ת������ǰ�ڵ��Ϊ���ӽڵ�����ӽڵ�
//        l_son->right = node;
//        // ���µ�ǰ�ڵ�ĸ��ڵ�Ϊ���ӽڵ�
//        node->parent = l_son;
//    }
//
//    // ����
//    // �������ĶԳ����, �߼���������һ����
//    void leftRotate(Node* node) {
//        Node* r_son = node->right;
//
//        node->right = r_son->left;
//
//        if (r_son->left) {
//            r_son->left->parent = node;
//        }
//
//        r_son->parent = node->parent;
//        if (!node->parent) {
//            root = r_son;
//        }
//        else if (node == node->parent->left) {
//            node->parent->left = r_son;
//        }
//        else {
//            node->parent->right = r_son;
//        }
//
//        r_son->left = node;
//        node->parent = r_son;
//    }
//
//    // �����޸�����
//    void insertFixup(Node* target) {
//        // ��Ŀ��ڵ�ĸ��ڵ�����Ҹ��ڵ����ɫ�Ǻ�ɫʱ����Ҫ�޸�
//        while (target->parent && target->parent->color == Color::RED) {
//            // ��Ŀ��ڵ�ĸ��ڵ����游�ڵ�����ӽڵ�ʱ
//            if (target->parent == target->parent->parent->left) {
//                Node* uncle = target->parent->parent->right; // ����ڵ�
//                // �������ڵ������Ϊ��ɫ��������ɫ����
//                if (uncle && uncle->color == Color::RED) {
//                    target->parent->color = Color::BLACK; // ���ڵ���Ϊ��ɫ
//                    uncle->color = Color::BLACK;          // ����ڵ���Ϊ��ɫ
//                    target->parent->parent->color = Color::RED; // �游�ڵ���Ϊ��ɫ
//                    target = target->parent->parent; // ���游�ڵ���Ϊ��һ��Ŀ��ڵ�
//                }
//                else {
//                    // ���Ŀ��ڵ��Ǹ��ڵ�����ӽڵ㣬��������ת
//                    if (target == target->parent->right) {
//                        target = target->parent; // ����Ŀ��ڵ�Ϊ���ڵ�
//                        leftRotate(target);      // ��Ŀ��ڵ��������
//                    }
//                    // �������ڵ���游�ڵ����ɫ������������ת
//                    target->parent->color = Color::BLACK;
//                    target->parent->parent->color = Color::RED;
//                    rightRotate(target->parent->parent);
//                }
//            }
//            else {
//                // ��Ŀ��ڵ�ĸ��ڵ����游�ڵ�����ӽڵ�ʱ��������Գ�
//                Node* uncle = target->parent->parent->left; // ����ڵ�
//                if (uncle && uncle->color == Color::RED) {
//                    target->parent->color = Color::BLACK;
//                    uncle->color = Color::BLACK;
//                    target->parent->parent->color = Color::RED;
//                    target = target->parent->parent;
//                }
//                else {
//                    if (target == target->parent->left) {
//                        target = target->parent; // ����Ŀ��ڵ�Ϊ���ڵ�
//                        rightRotate(target);     // ��Ŀ��ڵ��������
//                    }
//                    // �������ڵ���游�ڵ����ɫ������������ת
//                    target->parent->color = Color::BLACK;
//                    target->parent->parent->color = Color::RED;
//                    leftRotate(target->parent->parent);
//                }
//            }
//        }
//        // ȷ�����ڵ�ʼ��Ϊ��ɫ
//        root->color = Color::BLACK;
//    }
//
//    // ����ڵ㺯��
//    void insertNode(const Key& key, const Value& value) {
//        // ����һ���½ڵ㣬�ڵ����ɫ��ʼ��Ϊ��ɫ
//        Node* newNode = new Node(key, value, Color::RED);
//        Node* parent = nullptr; // �½ڵ�ĸ��ڵ�ָ��
//        Node* cmpNode = root;   // ���ڱȽϵĽڵ㣬��ʼΪ���ڵ�
//
//        // ���������ҵ��½ڵ����ȷλ��
//        while (cmpNode) {
//            parent = cmpNode; // ������ǰ�ڵ���Ϊ�½ڵ��Ǳ�ڸ��ڵ�
//            // ����½ڵ�ļ�С�ڵ�ǰ�ȽϽڵ�ļ��������������ƶ�
//            if (newNode->key < cmpNode->key) {
//                cmpNode = cmpNode->left;
//                // ����½ڵ�ļ����ڵ�ǰ�ȽϽڵ�ļ��������������ƶ�
//            }
//            else if (newNode->key > cmpNode->key) {
//                cmpNode = cmpNode->right;
//                // �������ȣ���˵������������ͬ���Ľڵ㣬ɾ���½ڵ㲢����
//            }
//            else {
//                delete newNode;
//                return;
//            }
//        }
//
//        // ���Ĵ�С����
//        size++;
//
//        // ���½ڵ�ĸ��ڵ�����Ϊ�ҵ��ĸ��ڵ�λ��
//        newNode->parent = parent;
//        // ������ڵ�Ϊ�գ�˵�����ǿյģ��½ڵ��Ϊ���ڵ�
//        if (!parent) {
//            root = newNode;
//            // ����½ڵ�ļ�С�ڸ��ڵ�ļ������½ڵ���븸�ڵ��������
//        }
//        else if (newNode->key < parent->key) {
//            parent->left = newNode;
//            // ���򣬽��½ڵ���븸�ڵ��������
//        }
//        else {
//            parent->right = newNode;
//        }
//
//        // �����½ڵ�󣬵���insertFixup�������޸������ƻ��ĺ��������
//        insertFixup(newNode);
//    }
//
//    // �������
//    void inorderTraversal(Node* node) const {
//        if (node) {
//            inorderTraversal(node->left);
//            std::cout << node->key << " ";
//            std::cout << node->value << " ";
//            inorderTraversal(node->right);
//        }
//    }
//    // �������������½ڵ��滻�ɽڵ�
//    void replaceNode(Node* targetNode, Node* newNode) {
//        if (!targetNode->parent) {
//            root = newNode;
//        }
//        else if (targetNode == targetNode->parent->left) {
//            targetNode->parent->left = newNode;
//        }
//        else {
//            targetNode->parent->right = newNode;
//        }
//        if (newNode) {
//            newNode->parent = targetNode->parent;
//        }
//    }
//
//    // Ѱ����ĳ���ڵ�Ϊ���ڵ�������е���С�ڵ�
//    Node* findMinimumNode(Node* node) {
//        while (node->left) {
//            node = node->left;
//        }
//        return node;
//    }
//
//    // removeFixup����������ɾ���ڵ��ָ������������
//    void removeFixup(Node* node) {
//        // ����ڵ�ΪNil����û�и��ڵ㣬˵������Ψһ�Ľڵ㣬ֱ�ӷ���
//        if (node == Nil && node->parent == nullptr) {
//            return;
//        }
//
//        // ������û�е�����ڵ�ʱ����ѭ��
//        while (node != root) {
//            // ����ڵ����丸�ڵ�����ӽڵ�
//            if (node == node->parent->left) {
//                // �ֵܽڵ��ǽڵ㸸�׵����ӽڵ�
//                Node* sibling = node->parent->right;
//
//                // ���1���ڵ���ֵܽڵ��Ǻ�ɫ
//                if (getColor(sibling) == Color::RED) {
//                    // ������ɫ�ֵܽڵ�͸��ڵ㣬����������
//                    setColor(sibling, Color::BLACK);
//                    setColor(node->parent, Color::RED);
//                    leftRotate(node->parent);
//                    // ��ת������ֵܽڵ�
//                    sibling = node->parent->right;
//                }
//
//                // ���2���ֵܽڵ�������ӽڵ㶼�Ǻ�ɫ
//                if (getColor(sibling->left) == Color::BLACK &&
//                    getColor(sibling->right) == Color::BLACK) {
//                    // ������ɫ�ֵܽڵ㲢�����ƶ�
//                    setColor(sibling, Color::RED);
//                    node = node->parent;
//                    // ������ڵ��Ǻ�ɫ�������Ϊ��ɫ������
//                    if (node->color == Color::RED) {
//                        node->color = Color::BLACK;
//                        node = root;
//                    }
//                }
//                else {
//                    // ���3���ֵܽڵ�����ӽڵ��Ǻ�ɫ�����ӽڵ��Ǻ�ɫ��
//                    if (getColor(sibling->right) == Color::BLACK) {
//                        // ������ɫ�ֵܽڵ���ֵܽڵ�����ӽڵ㣬����������
//                        setColor(sibling->left, Color::BLACK);
//                        setColor(sibling, Color::RED);
//                        rightRotate(sibling);
//                        // ��ת������ֵܽڵ�
//                        sibling = node->parent->right;
//                    }
//
//                    // ���4���ֵܽڵ�����ӽڵ��Ǻ�ɫ
//                    setColor(sibling, getColor(node->parent));
//                    setColor(node->parent, Color::BLACK);
//                    setColor(sibling->right, Color::BLACK);
//                    leftRotate(node->parent);
//                    // �ƶ������ڵ����
//                    node = root;
//                }
//            }
//            else {
//                // ���ڵ����丸�ڵ�����ӽڵ�ʱ���ԳƵ����
//                Node* sibling = node->parent->left;
//
//                if (getColor(sibling) == Color::RED) {
//                    setColor(sibling, Color::BLACK);
//                    setColor(node->parent, Color::RED);
//                    rightRotate(node->parent);
//                    sibling = node->parent->left;
//                }
//
//                if (getColor(sibling->right) == Color::BLACK &&
//                    getColor(sibling->left) == Color::BLACK) {
//                    setColor(sibling, Color::RED);
//                    node = node->parent;
//                    if (node->color == Color::RED) {
//                        node->color = Color::BLACK;
//                        node = root;
//                    }
//                }
//                else {
//                    if (getColor(sibling->left) == Color::BLACK) {
//                        setColor(sibling->right, Color::BLACK);
//                        setColor(sibling, Color::RED);
//                        leftRotate(sibling);
//                        sibling = node->parent->left;
//                    }
//                    setColor(sibling, getColor(node->parent));
//                    setColor(node->parent, Color::BLACK);
//                    setColor(sibling->left, Color::BLACK);
//                    rightRotate(node->parent);
//                    node = root;
//                }
//            }
//        }
//        // ȷ����ǰ�ڵ��Ǻ�ɫ�ģ���ά�ֺ��������
//        setColor(node, Color::BLACK);
//    }
//
//    // ��ȡ��ɫ, ��ָ��Ϊ��ɫ
//    Color getColor(Node* node) {
//        if (node == nullptr) {
//            return Color::BLACK;
//        }
//        return node->color;
//    }
//
//    void setColor(Node* node, Color color) {
//        if (node == nullptr) {
//            return;
//        }
//        node->color = color;
//    }
//
//    // ȡ��Nil�ڱ�������
//    void dieConnectNil() {
//        if (Nil == nullptr) {
//            return;
//        }
//        if (Nil->parent != nullptr) {
//            if (Nil == Nil->parent->left) {
//                Nil->parent->left = nullptr;
//            }
//            else {
//                Nil->parent->right = nullptr;
//            }
//        }
//    }
//
//    // ɾ���ڵ�
//    void deleteNode(Node* del) {
//        Node* rep = del; // rep������ڵ㣩��ʼָ��Ҫɾ���Ľڵ�
//        Node* child = nullptr;      // Ҫɾ���ڵ�ĺ��ӽڵ�
//        Node* parentRP;             // ����ڵ�ĸ��ڵ�
//        Color origCol = rep->color; // ����Ҫɾ���ڵ��ԭʼ��ɫ
//
//        // ���ɾ���ڵ�û������
//        if (!del->left) {
//            rep = del->right;        // ����ڵ�ָ��ɾ���ڵ���Һ���
//            parentRP = del->parent;  // ��������ڵ�ĸ��ڵ�
//            origCol = getColor(rep); // ��ȡ����ڵ����ɫ
//            replaceNode(del, rep);   // ������ڵ��滻ɾ���ڵ�
//        }
//        // ���ɾ���ڵ�û���Һ���
//        else if (!del->right) {
//            rep = del->left;         // ����ڵ�ָ��ɾ���ڵ������
//            parentRP = del->parent;  // ��������ڵ�ĸ��ڵ�
//            origCol = getColor(rep); // ��ȡ����ڵ����ɫ
//            replaceNode(del, rep);   // ������ڵ��滻ɾ���ڵ�
//        }
//        // ���ɾ���ڵ�����������
//        else {
//            rep = findMinimumNode(
//                del->right); // �ҵ�ɾ���ڵ��������е���С�ڵ���Ϊ����ڵ�
//            origCol = rep->color; // ��������ڵ��ԭʼ��ɫ
//            // �������ڵ㲻��ɾ���ڵ��ֱ���Һ���
//            if (rep != del->right) {
//                parentRP = rep->parent; // ��������ڵ�ĸ��ڵ�
//                child = rep->right; // ����ڵ���Һ��ӱ��Ҫ����ĺ��ӽڵ�
//                parentRP->left =
//                    child; // ����ڵ�ĸ��ڵ������ָ������ڵ�ĺ��ӣ���Ϊ����ڵ�����С�ڵ㣬���Բ����������ӣ�
//                if (child != nullptr) {
//                    child->parent = parentRP; // �������ڵ�ĺ��Ӵ��ڣ�������丸�ڵ�
//                }
//                // ������ڵ�ŵ�ɾ���ڵ��λ��
//                del->left->parent = rep;
//                del->right->parent = rep;
//                rep->left = del->left;
//                rep->right = del->right;
//                // ���ɾ���ڵ��и��ڵ㣬���¸��ڵ�ĺ���ָ��
//                if (del->parent != nullptr) {
//                    if (del == del->parent->left) {
//                        del->parent->left = rep;
//                        rep->parent = del->parent;
//                    }
//                    else {
//                        del->parent->right = rep;
//                        rep->parent = del->parent;
//                    }
//                }
//                // ���ɾ���ڵ�û�и��ڵ㣬˵�����Ǹ��ڵ�
//                else {
//                    root = rep;
//                    root->parent = nullptr;
//                }
//            }
//            // �������ڵ���ɾ���ڵ��ֱ���Һ���
//            else {
//                child = rep->right; // ���ӽڵ�ָ������ڵ���Һ���
//                rep->left = del->left; // ����ڵ������ָ��ɾ���ڵ������
//                del->left->parent = rep; // �������ӵĸ��ڵ�
//                // ����ɾ���ڵ㸸�ڵ�ĺ���ָ��
//                if (del->parent != nullptr) {
//                    if (del == del->parent->left) {
//                        del->parent->left = rep;
//                        rep->parent = del->parent;
//                    }
//                    else {
//                        del->parent->right = rep;
//                        rep->parent = del->parent;
//                    }
//                }
//                // ���ɾ���ڵ��Ǹ��ڵ�
//                else {
//                    root = rep;
//                    root->parent = nullptr;
//                }
//                parentRP = rep; // ��������ڵ�ĸ��ڵ�
//            }
//        }
//
//        // �������ڵ���ڣ���������ɫΪɾ���ڵ����ɫ
//        if (rep != nullptr) {
//            rep->color = del->color;
//        }
//        // �������ڵ㲻���ڣ���ɾ���ڵ����ɫ����origCol����
//        else {
//            origCol = del->color;
//        }
//
//        // ���ԭʼ��ɫ�Ǻ�ɫ����Ҫ���ж�����޸���������Ϊ��ɫ�ڵ��ɾ�����ܻ��ƻ������������
//        if (origCol == Color::BLACK) {
//            // ������ں��ӽڵ㣬�����޸�����
//            if (child != nullptr) {
//                removeFixup(child);
//            }
//            // ��������ں��ӽڵ㣬��Nil�ڵ㣨����սڵ㣩�ĸ��ڵ�����Ϊ����ڵ�ĸ��ڵ�
//            else {
//                Nil->parent = parentRP;
//                // �������ڵ�ĸ��ڵ���ڣ��������Ӧ�ĺ���ָ��ΪNil�ڵ�
//                if (parentRP != nullptr) {
//                    if (parentRP->left == nullptr) {
//                        parentRP->left = Nil;
//                    }
//                    else {
//                        parentRP->right = Nil;
//                    }
//                }
//                // �����޸�����
//                removeFixup(Nil);
//                // �Ͽ�Nil�ڵ����������ӣ���Ϊ�ں������Nil�ڵ�ͨ���ǵ������ڵ�
//                dieConnectNil();
//            }
//        }
//
//        // ɾ���ڵ�
//        delete del;
//    }
//
//public:
//    // ���캯��
//    RedBlackTree() : root(nullptr), size(0), Nil(new Node()) {
//        Nil->color = Color::BLACK;
//    }
//
//    // ����
//    void insert(const Key& key, const Value& value) { insertNode(key, value); }
//
//    // ɾ��
//    void remove(const Key& key) {
//        Node* nodeToBeRemoved = lookUp(key);
//        if (nodeToBeRemoved != nullptr) {
//            deleteNode(nodeToBeRemoved);
//            size--;
//        }
//    }
//
//    Value* at(const Key& key) {
//        auto ans = lookUp(key);
//        if (ans != nullptr) {
//            return &ans->value;
//        }
//        return nullptr;
//    }
//
//    int getSize() { return size; }
//
//    bool empty() { return size == 0; }
//
//    // ���������ӡ
//    void print() {
//        inorderTraversal(root);
//        std::cout << std::endl;
//    }
//
//    void clear() {
//        deleteNode(root);
//        size = 0;
//    }
//
//    // ��������
//    ~RedBlackTree() {
//        // �ͷŽڵ��ڴ�
//        deleteTree(root);
//    }
//
//private:
//    // �ݹ��ͷŽڵ��ڴ�
//    void deleteTree(Node* node) {
//        if (node) {
//            deleteTree(node->left);
//            deleteTree(node->right);
//            delete node;
//        }
//    }
//};
//
