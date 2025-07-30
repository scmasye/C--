#include <iostream>
#include <vector>
#include <string>

int main() {
    // 创建一个字符串向量
    std::vector<std::string> messages = {"Hello", "from", "your", "M4", "Mac!"};
    
    // 打印欢迎信息
    std::cout << "Starting C++ program..." << std::endl;

    // 循环遍历并打印向量中的每个词
    for (const std::string& word : messages) {
        std::cout << word << " ";
    }
    
    std::cout << std::endl;
    
    // 在这里设置一个断点来观察变量
    std::cout << "Program finished. Press Enter to exit." << std::endl;
    
    // 等待用户输入，防止终端窗口在调试时一闪而过
    std::cin.get();
    
    return 0;
}