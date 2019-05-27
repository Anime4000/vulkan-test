#include <stdio.h>

__declspec(dllimport) void *LoadLibraryA(char *);
__declspec(dllimport) void *GetProcAddress(void *, char *);

int main()
{
    void *vk = LoadLibraryA("vulkan-1.dll");
    if (!vk)
	{
		printf("Vulkan drivers not installed.");
		return -1;
	}

    void *(*vkGetInstanceProcAddr)(void *, const char *) = GetProcAddress(vk, "vkGetInstanceProcAddr");
    if (!vkGetInstanceProcAddr)
	{
		printf("Vulkan is malfunctioning (vkGetInstanceProcAddr).");
		return 3;
	}

    int (*vkCreateInstance)(int *, void *, void **) = vkGetInstanceProcAddr(0, "vkCreateInstance");
    if (!vkCreateInstance)
	{
		printf("Vulkan is malfunctioning (vkCreateInstance)");
		return 2;
	}
	
    void *instance = 0;
    int result = vkCreateInstance((int[16]){1}, 0, &instance);
    if (!instance || result != 0)
    {
		printf("Vulkan drivers installed and functioning but are incompatible. An instance could not be created.");
		return 1;
	}
	
    printf("Successfully created a Vulkan instance.");
	return 0;
}
