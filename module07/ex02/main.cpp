#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	try {
		std::cout << "✅ int配列テスト" << std::endl;
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); ++i)
			a[i] = i * 10;

		for (unsigned int i = 0; i < a.size(); ++i)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;

		std::cout << "\n✅ コピーコンストラクタの確認" << std::endl;
		Array<int> b = a;
		b[0] = 999;
		std::cout << "a[0] = " << a[0] << " (should be 0)" << std::endl;
		std::cout << "b[0] = " << b[0] << " (should be 999)" << std::endl;

		std::cout << "\n✅ string配列テスト" << std::endl;
		Array<std::string> s(3);
		s[0] = "apple";
		s[1] = "banana";
		s[2] = "cherry";
		for (unsigned int i = 0; i < s.size(); ++i)
			std::cout << "s[" << i << "] = " << s[i] << std::endl;

		std::cout << "\n✅ 範囲外アクセスチェック" << std::endl;
		std::cout << s[10] << std::endl; // 例外が投げられるはず

	} catch (std::exception& e) {
		std::cerr << "❌ Exception: " << e.what() << std::endl;
	}

	return 0;
}
