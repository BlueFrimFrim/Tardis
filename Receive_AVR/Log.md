### 2017-06-13
#### Log 1 01:03
Added 'receive_avr.cpp' to project. There is no '.h' file because all the
functions are declared in 'tardis.h'. 

Basicallys each Arduino in the tardis system will have it's own `main_task()` 
and `setup_task()`. This way you will just have to call the setup function and 
the main_task function.

This means getting rid of all the structs. It's too complicated right now.
Therefor this it is very difficult to keep track of what is going on. 
We need to write it so it is well documented and each function should only do
sONE task.

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

`update()`: read mt8880c incoming tone

`process()`: handle the data from `update()`

`execute()`: execute command based on `process()`

**TODO:** 
- Edit dtmf.cpp/h further. 
  - Right now everything relies on structs from outside the .cpp file.
    This will be used for different parts of the Tardis so it needs to 
    be self-sufficient. 
#

### 2017-06-13
#### Log 2 22:40
'dtmf.cpp' and 'dtmf.h' are complete for the most part. They should no longer rely on a big 'struct' 
in order to function.

Future: Complete `update()`. 
- This should update the 7-segment displays, and read the dtmf chip.

#

### 2017-06-19
#### Log 3 23:36
Previous log said that `dtmf.cpp/h` was complete. However NOW it is complete
for testing.

`dtmf.cpp/h` changes:
- `static` functions are now at the start of the c++ files. The
`global` functions are at the bottom with a description. 

```C
/*
 * funtion-name - description
 * @func - short description
 * @data - variables that are passed
 *
 * @return - returned things
 * Note: here is a thing
 */
```

I have also added an `init.cpp/h` which is a structure of functions.
During `setup_task()` it will run all the initializations needed for 
the system. 

```C
/* Example */
void(*init[]) (void) = {
    init_fn1,
    init_fn2,
    init_fn3
};
```

**TODO:** 
- Get rid of `buffer.cpp/h`
- Make the same code style changes to receive_avr.cpp

### 2017-06-21
#### Log 4 23:45
Compiled `dtmf.cpp/h` and fixed all the errors. 

Started working on `receive_avr.cpp/h` and `irq.cpp/h`.

**TODO:**
- Finish writing `irq.cpp/h` so it compiled and is self-contained.
- Put TARDIS functionality into `update` `process` and `execute`.
  - _Note: Should `update` be split up into `update` and `fetch`. Put 
  `update` last, after `execute`.

### 2017-06-22
#### Log 4 22:53
Continued working on `receive_avr.cpp/h`

**TODO:**
- Integrate timeout into `main_task`

### 2017-07-11
#### Log 5 20:20
Previous log not useful....take note.

Moved into new condo, Tardis work will resume.

First things first. I have decided to move the 7-segment displays from the circuit.
The libraries don't always work with VisualMicro so it's not a critical feature and 
will be removed.

The project was a mess...I tried to break things up to make it 'simpler' however
I just made things worse. Basically I will just keep everything together for now.

### 2017-07-13
#### Log 6 20:45
Using `tardis-working-revision`. 

Added `timeout.cpp/h` which has the class for timeouts.

Example:

```C++
    Timeout_t timeout1 = Timeout_t(5000) // 5000ms -> 5s timeout
    timeout1.set_timeout(); // this sets the current time for reference
    if(timeout1.check()){ // check if 5s has passed. If yes, run event.
        event();
    }
```