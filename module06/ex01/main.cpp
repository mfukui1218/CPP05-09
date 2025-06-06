#include "Serializer.hpp"

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	// 元のデータオブジェクトを作成
	Data original;
	original.setValue(42);
	original.setStr("Hello, Serialization!");

	std::cout << "Original Data: " << original << std::endl;

	// ポインタをシリアライズ（uintptr_t に変換）
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

	// 再びポインタへデシリアライズ
	Data* restored = Serializer::deserialize(raw);
	std::cout << "Deserialized Data: " << *restored << std::endl;

	// 同一ポインタか確認
	if (restored == &original)
		std::cout << "✅ Success: Pointers match!" << std::endl;
	else
		std::cout << "❌ Error: Pointers do not match!" << std::endl;

	return 0;
}
