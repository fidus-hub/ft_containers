#pragma once
#include "Vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Stack
	{
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef size_t			size_type;

			explicit	Stack (const container_type& ctnr = container_type()) : ct(ctnr){}

			bool		empty() const
			{
				return (ct.empty());
			};
			size_type	size() const
			{
				return (ct.size());
			};
			value_type&	top()
			{
				return (ct.back());
			};
			const value_type&	top() const
			{
				return (ct.back());
			};
			void		push (const value_type& val)
			{
				ct.push_back(val);
			};
			void		pop()
			{
				ct.pop_back();
			};

		template< class I, class Container2 >
		friend bool operator==( const Stack<I,Container2>& lhs, const Stack<I,Container2>& rhs );
			template< class I, class Container2 >
		friend bool operator!=( const Stack<I,Container2>& lhs, const Stack<I,Container2>& rhs );
			template< class I, class Container2 >
		friend bool operator<( const Stack<I,Container2>& lhs, const Stack<I,Container2>& rhs );
			template< class I, class Container2 >
		friend bool operator<=( const Stack<I,Container2>& lhs, const Stack<I,Container2>& rhs );
			template< class I, class Container2 >
		friend bool operator>( const Stack<I,Container2>& lhs, const Stack<I,Container2>& rhs );
			template< class I, class Container2 >
		friend bool operator>=( const Stack<I,Container2>& lhs, const Stack<I,Container2>& rhs );


		protected:
			container_type ct;

	};

			template< class T, class Container >
		bool operator==( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
			return(lhs.ct == rhs.ct);
		}

			template< class T, class Container >
		bool operator!=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
			return (lhs.ct != rhs.ct);
		}

			template< class T, class Container >
		bool operator<( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
			return (lhs.ct < rhs.ct);
		}

			template< class T, class Container >
		bool operator<=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
			return (lhs.ct <= rhs.ct);
		}

			template< class T, class Container >
		bool operator>( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
			return (lhs.ct > rhs.ct);
		}

			template< class T, class Container >
		bool operator>=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
			return (lhs.ct >= rhs.ct);
		}

}