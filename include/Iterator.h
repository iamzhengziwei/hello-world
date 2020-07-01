#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include <cstddef>
namespace mySTL{

	struct input_iterator_tag{};  //返回输入迭代器
	struct output_iterator_tag{};  //返回输出迭代器
	struct forward_iterator_tag :public input_iterator_tag {};  //前向迭代器
	struct bidirectional_iterator_tag :public forward_iterator_tag {};  //双向迭代器
	struct random_access_iterator_tag :public bidirectional_iterator_tag {};  // 随机迭代器

	template <class T, class Distance> struct input_iterator
	{
		typedef input_iterator_tag	iterator_category;  //返回类型
		typedef T					value_type;			//所指对象类型
		typedef Distance			difference_type;	//迭代器间距离类型
		typedef T*					pointer;			//操作结果类型
		typedef T&					reference;			//解引用操作结果类型
	};
	struct output_iterator
	{
		typedef output_iterator_tag iterator_category;
		typedef void                value_type;
		typedef void                difference_type;
		typedef void                pointer;
		typedef void                reference;
	};
	template <class T, class Distance> struct forward_iterator
	{
		typedef forward_iterator_tag	iterator_category;
		typedef T						value_type;
		typedef Distance				difference_type;
		typedef T*						pointer;
		typedef T&						reference;
	};
	template <class T, class Distance> struct bidirectional_iterator
	{
		typedef bidirectional_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef Distance					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};
	template <class T, class Distance> struct random_access_iterator
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef Distance					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};

	//为避免挂一漏百，自行开发的迭代器最好继承自以下这个std::iterator
	template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference 			reference;
	};
	template<class T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag 	iterator_category;
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef T*							pointer;
		typedef T& 							reference;
	};
	template<class T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag 	iterator_category;
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef const T*					pointer;
		typedef const T& 					reference;
	};

	template<class Iterator>
	inline typename iterator_traits<Iterator>::iterator_category
		iterator_category(const Iterator& It){
			typedef typename iterator_traits<Iterator>::iterator_category category;
		return category();
	}
	template<class Iterator>
	inline typename iterator_traits<Iterator>::value_type*
		value_type(const Iterator& It){
		return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
	}
	template<class Iterator>
	inline typename iterator_traits<Iterator>::difference_type*
		difference_type(const Iterator& It){
		return static_cast<typename iterator_traits<Iterator>::difference_type*>(0);
	}
}

#endif
