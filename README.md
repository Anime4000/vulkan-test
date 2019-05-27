# World's Smallest Vulkan Compatability Test

This tiny program checks if your Windows system is capable of creating
a Vulkan instance. If not, it will give a hint as to why (missing
drivers, malfunctioning drivers, incompatible drivers).

# Error Return Code
You can intergrate this mini program into your application
and capture `vulkan_test.exe` return code.

## Return Code:
* -1: Vulkan API not installed, unsupported GPU.
*  0: Vulkan API is available
*  1: Vulkan drivers installed and functioning but are incompatible. An instance could not be created.
*  2: Vulkan is malfunctioning (vkCreateInstance)
*  3: Vulkan is malfunctioning (vkGetInstanceProcAddr).
