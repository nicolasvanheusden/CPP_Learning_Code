// #include <iostream>
// #include <memory>
// #include <string>
// #include <utility>
// #include <vector>

// std::unique_ptr<int> passthrough(std::unique_ptr<int> i) {
//     auto res = std::move(i);
//     return res;
// }

// void display(const std::string& variable_name, const std::unique_ptr<int>& variable) {
//     if (variable == nullptr) {
//         std::cout << variable_name << " is empty " << std::endl;
//     } else {
//         std::cout << variable_name << " contains " << *variable << std::endl;
//     }
// }

// int main() {
//     auto i1 = std::make_unique<int>(3);
//     auto i2 = std::make_unique<int>(8);

//     std::cout << "Before passthrough call" << std::endl;
//     display("i1", i1);
//     display("i2", i2);
//     std::cout << "--------------------------" << std::endl;

//     i2 = passthrough(std::move(i1));

//     std::cout << "After passthrough call" << std::endl;
//     display("i1", i1);
//     display("i2", i2);
//     std::cout << "--------------------------" << std::endl;

//     return 0;
// }

#include <memory>
#include <string>
#include <vector>

struct Resource {
    Resource(const std::string& content)
        : _content { content } {}

    std::string _content;
};

// Index objects of type Resource and handle their lifespans.
class ResourceManager {
public:
    // Create a new resource.
    // Return the index where the resource was created.
    size_t create(const std::string& content) {
        _resources.emplace_back(std::make_unique<Resource>(Resource { content }));
        return _resources.size() - 1;
    }

    // Destroy the resource at the given index.
    // The other elements keep the same index, we do not reorganize the array.
    void destroy(size_t index) { _resources.at(index).reset(); }

    // Take the ownership of an existing resource.
    // Return the index where the resource was placed.
    size_t acquire(std::unique_ptr<Resource> resource) {
        for (size_t i = 0; i < _resources.size(); i++) {
            if (resource == _resources.at(i)) {
                return i;
            }
        }
        return 0;
    }

    // Transfer the resource at the given index to the caller.
    std::unique_ptr<Resource> yield(size_t index) {
        auto res = std::move(_resources.at(index));
        return res;
    }

    // Provide access to the resource at the given index.
    Resource& get(size_t index) const { return *_resources.at(index); }

private:
    std::vector<std::unique_ptr<Resource>> _resources;
};

int main() {
}