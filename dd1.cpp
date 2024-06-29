#include <iostream>
#include <vector>

class Node {
public:
    int points;
    int capacity;
    std::vector<Node*> children;

    Node(int pts, int cap) : points(pts), capacity(cap) {}

    void divide() {
        int pointsPerChild = points / 8;
        for (int i = 0; i < 8; ++i) {
            children.push_back(new Node(pointsPerChild, capacity));
        }
        points = points % 8;  // Remaining points in the current node
    }

    void print(int level = 0) {
        for (int i = 0; i < level; ++i) std::cout << "--";
        std::cout << "Node(points: " << points << ", capacity: " << capacity << ")\n";
        for (auto* child : children) {
            child->print(level + 1);
        }
    }
};

void createTree(Node& node) {
    if (node.points > node.capacity) {
        node.divide();
        for (auto* child : node.children) {
            std::cout << "Enter points for child node: ";
            std::cin >> child->points;
            createTree(*child);
        }
    }
}

int main() {
    int totalPoints = 1000;
    int initialPoints, capacity;

    std::cout << "Enter points for the root node: ";
    std::cin >> initialPoints;

    std::cout << "Enter capacity for each node: ";
    std::cin >> capacity;

    Node root(initialPoints, capacity);

    createTree(root);

    std::cout << "\nOak Tree Structure:\n";
    root.print();

}
