
#include "stack.h"

// Use this method for all your reallocations:

void stack::ensure_capacity( size_t c ) 
{
   if( current_capacity < c )
   {
      // New capacity will be the greater of c and
      // 2 * current_capacity. 

      if( c < 2 * current_capacity )
         c = 2 * current_capacity;

      double* newdata = new double[ c ];
      for( size_t i = 0; i < current_size; ++ i )
         newdata[i] = data[i];

      current_capacity = c;
      delete[] data;
      data = newdata;
   }
}

stack::stack( const stack& s ) // 2. copy constructor
{
	data = new double [ s.current_capacity + 1];
	current_capacity = s.current_capacity + 1;
	size_t i = 0;
	while ( i < s.current_size )
	{
		data[i] = s.data[i];
		i++;
	}
	current_size = i;
}

stack::~stack() // 3. destructor
{
	delete [] data;
}

const stack& stack::operator = ( const stack& s ) // 4. assignment
{
	ensure_capacity( s.current_size + 1 );
	size_t i = 0;
	while ( i < s.current_size )
	{
		data[i] = s.data[i];
		i++;
	}
	current_size = i;
	return s; 
}

stack::stack( std::initializer_list<double> num ) // 5. initializer
{
	size_t i = 0;
	current_capacity = num.size();
	data = new double[num.size()];
	for( double in : num )
	{
		data[i++] = in;
	}
	current_size = i;	
}

void stack::push( double d ) //6. Push function
{	
	while ( current_size == current_capacity )
		ensure_capacity( current_size + 1 );
	data[current_size] = d;
	current_size += 1;
}


void stack::clear() // 8. clear function
{
	while (current_size > 0) {
		data[current_size] = 0;
		current_size--;
	}
}
	
void stack::reset( size_t s )  // 9. Reset function
{
	if ( current_capacity > s ) {
		current_capacity = s;
		double* newdata = new double[ s ];
		for (size_t i = 0; i < s; i++)
			newdata[i] = data[i];
		delete[] data;
		data = newdata;
		if ( s < current_size)
			current_size = s;
	}
}

double stack::peek() const // 10. seeing the top element of the stack
{
	//for both cases return and cout
	//std::cout << data[current_size] << " elenement " << std::endl;
	return data[current_size - 1];
}

size_t stack::size( ) const // 11. return the current size of the stack
{
	return current_size;
}

bool stack::empty( ) const // 12. return 'true' if the stack is empty
{
	if (current_size == 0)
		return true;
	else
		return false;
}

std::ostream& operator << ( std::ostream& on, const stack& s ) //13. cout
{
	for (size_t i = 0; i < s.current_size; i++)
		on << s.data[i] << ' ';
	return on;
}