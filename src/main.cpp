#include "PNG_Container.hpp"
#include "SageJSON.hpp"
#include <crtdbg.h>
#include <chrono>

#define _CRTDBG_MAP_ALLOC
//#define STB_IMAGE_IMPLEMENTATION
const char* data = "../SageIO/data/test_json_files.json";
const char* output = "../SageIO/data/output.json";
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using JSON = SageJSON::SageJSON;
int main()
{
	//Execution time
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SageJSON::SageJSON json{};

	std::ifstream file(data);
	std::ofstream lol(output);

	if (!file)
		return 1;

	while (!file.eof())
	{
		file >> json;
		
		/*std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		
		double elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

		std::cout << "Execution time: " << elapsed_time << " ms" << std::endl;*/
	}
	
	lol << json;

	
	


	auto v = json["header"]["files_per_second"];

	std::cout << v.as<JSON::NumberValue>() << std::endl;
	json.close();

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	double elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

	std::cout << "Execution time: " << elapsed_time << " ms" << std::endl;
	
    return 0;
}