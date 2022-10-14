#ifndef STACK_HPP
# define STACK_HPP

#include "deque.hpp"

namespace ft
{
	template <class T, class Container = deque<T> >
	class stack
	{
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef size_t			size_type;

			explicit	stack (const container_type& ctnr = container_type()) : ct(ctnr){}

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
				return (ct.push_back());
			};
			void		pop()
			{
				return (ct.pop_back());
			};
		protected:
			container_type ct;

	}

	template< class T, class Container >
		bool operator==( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs ){
			return(lhs.ct == rhs.ct);
		}

	template< class T, class Container >
		bool operator!=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs ){
			return (lhs.ct != rhs.ct);
		}

	template< class T, class Container >
		bool operator<( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs ){
			return (lhs.ct < rhs.ct);
		}

	template< class T, class Container >
		bool operator<=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs ){
			return (lhs.ct <= rhs.ct);
		}

	template< class T, class Container >
		bool operator>( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs ){
			return (lhs.ct > rhs.ct);
		}

	template< class T, class Container >
		bool operator>=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs ){
			return (lhs.ct >= rhs.ct);
		}



}