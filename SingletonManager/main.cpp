#include "SingletonManager.h"
#include "Manager1.h"
#include "Manager2.h"
#include "Manager3.h"
#include "Manager4.h"

using namespace std;

int main()
{
	SingletonManager manager;
	manager.Init();

	Manager1::GetInstance().Display();
	Manager2::GetInstance().Display();
	Manager3::GetInstance().Display();
	Manager4::GetInstance().Display();

	manager.Shutdown();
	
	return 0;
}
