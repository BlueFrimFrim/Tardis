### 2017-06-13
#### Log 1 01:03
 Added 'receive_avr.cpp' to project. There is no '.h' file because all the functions are declared
    in 'tardis.h'. 

Basicallys each Arduino in the tardis system will have it's own `main_task()` and `xxx_setup()`.
This way you will just have to call the setup function and the main_task function.

This means getting rid of all the structs. It's too complicated right now. Therefor this it is
very difficult to keep track of what is going on. We need to write it so it is well documented
and each function should only do ONE task.

I've split the `main_task()` into 3 functions:

```C
unsigned int main_task()
{
	update();
	process();
	execute();
	return 0;
}
```

`update()`: read the dtmf register and fill the buffer when an interrupt is tripped.

`process()`: process the data into different commands and return them so they can be
				passes to the transmit_avr. 

`execute()`: send the data to the transmit_avr Arduino, where it will be processed further.

> Future: Edit dtmf.cpp/h further. 
> - Right now everything relies on structs from outside the .cpp file.
    This will be used for different parts of the Tardis so it needs to be self-sufficient. 

### 2017-06-13
#### Log 2 22:40
'dtmf.cpp' and 'dtmf.h' are complete for the most part. They should no longer rely on a big 'struct' 
in order to function.

> Future: Complete `update()`. 
> - This should update the 7-segment displays, and read the dtmf chip.