#include <fcntl.h>	// open()
#include <unistd.h>	// close()
#include <stdio.h>
#include <stddef.h>
#include "lmt_c_library.h"

#define EXECUTE	ato_test



int	ato_test(int argc, char **argv)
{
	int				int_value;
	long			long_value;
	unsigned int	unsigned_int_value;

	if (argc != 2)
	{
		printf("usage: %s <number_str>\n", argv[0]);
		return (NORMAL);
	}

	if (lmt_atoi(argv[1], &int_value) == PARSE_SUCCESS)
		printf("Convert to int: [%d]\n", int_value);
	else
		printf("Failed converting str to int.\n");
	if (lmt_atol(argv[1], &long_value) == PARSE_SUCCESS)
		printf("Convert to long: [%ld]\n", long_value);
	else
		printf("Failed converting str to long.\n");
	if (lmt_atoui(argv[1], &unsigned_int_value) == PARSE_SUCCESS)
		printf("Convert to unsigned int: [%u]\n", unsigned_int_value);
	else
		printf("Failed converting str to unsigned int.\n");
	return (NORMAL);
}



int	lmt_io_test(int argc, char **argv)
{
	t_lmt_string	*string;
	char			buffer[513];
	int				fd;
	int				count_reads;

	if (argc != 2)
	{
		string = lmt_string_new("usage: ");
		if (string == NULL)
			return (ERROR);
		if (lmt_string_append_string(string, argv[0]) != NORMAL)
			return (ERROR);
		if (lmt_string_append_string(string, " <file path to display>\n") != NORMAL)
			return (ERROR);
		if (lmt_write(1, string->str) == -1)
			return (ERROR);
		lmt_string_free(string);
		return (NORMAL);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		string = lmt_string_new("Opening [");
		if (string == NULL)
			return (ERROR);
		if (lmt_string_append_string(string, argv[1]) != NORMAL)
			return (ERROR);
		if (lmt_string_append_string(string, "] failed!\n") != NORMAL)
			return (ERROR);
		if (lmt_write(1, string->str) == -1)
			return (ERROR);
		lmt_string_free(string);
		return (ERROR);
	}
	while ((count_reads = read(fd, buffer, 512)) > 0)
	{
		buffer[count_reads] = '\0';
		if (lmt_write(1, buffer) == -1)
			return (ERROR);
	}
	if (count_reads == -1)
		return (ERROR);
	close(fd);
	return (NORMAL);
}



static int	print_string(void *string);

int	lmt_list_test2(int argc, char **argv)
{
	t_lmt_list	*list;

	(void)argc;
	(void)argv;

	list = lmt_list_new();
	if (list == NULL)
		return (ERROR);
	if (lmt_list_append(list, lmt_string_new("hi")) != NORMAL)
		return (ERROR);
	if (lmt_list_append(list, lmt_string_new("there")) != NORMAL)
		return (ERROR);
	if (lmt_list_append(list, lmt_string_new("hello")) != NORMAL)
		return (ERROR);
	if (lmt_list_append(list, lmt_string_new("world")) != NORMAL)
		return (ERROR);

	if (lmt_list_iterate_for_each(list, print_string) != NORMAL)
		return (ERROR);

	lmt_list_free(list, (t_lmt_list_free_content)lmt_string_free);
	return (NORMAL);
}



static int	print_string(void *string)
{
	printf("%s \n", ((t_lmt_string *)string)->str);
	return (NORMAL);
}

int	lmt_list_test(int argc, char **argv)
{
	t_lmt_list		*list;
	void			*content;

	(void)argc;
	(void)argv;

	list = lmt_list_new();
	if (list == NULL)
		return (ERROR);

	content = lmt_string_new("hi");
	if (content == NULL)
		return (ERROR);
//		// 이 부분은 content 를 받아서 새로운 node 를 추가하도록 수정하면 좋겠다
//		element = lmt_list_new(content);
//		lmt_list_append(list, element);
	if (lmt_list_append(list, content) != NORMAL)
		return (ERROR);

	content = lmt_string_new("there");
	if (content == NULL)
		return (ERROR);
//		element = lmt_list_new(content);
//		lmt_list_append(list, element);
	if (lmt_list_append(list, content) != NORMAL)
		return (ERROR);

//		// 이 반복 기능은 lmt_list type 안에서 protocol method 로 작성하는 것이 맞다
//		if (list->prev != list)
//		{
//			iter = lmt_iterator_new(list->next, list->prev, string_list_next);
//			lmt_iterator_for_each(iter, print_string);
//			lmt_iterator_free(iter);
//		}
	if (lmt_list_iterate_for_each(list, print_string) != NORMAL)
		return (ERROR);

	lmt_list_free(list, (t_lmt_list_free_content)lmt_string_free);
	return (NORMAL);
}



static void	*int_array_next(void *array)
{
	return ((int *)array + 1);
}

static int	int_array_set_42(void *array)
{
	*(int *)array = 42;
	return (NORMAL);
}

static int	int_array_describe(void *array)
{
	printf("%d ", *(int *)array);
	return (NORMAL);
}

static int int_array_set_double_index(size_t index, void *array)
{
	*(int *)array = index * 2;
	return (NORMAL);
}

static int int_array_describe_with_index(size_t index, void *array)
{
	printf("[%zu]: %d\n", index, *(int *)array);
	return (NORMAL);
}

int	lmt_iterator_test(int argc, char **argv)
{
	int				array[10];
	t_lmt_iterator	*iter;

	(void)argc;
	(void)argv;
	iter = lmt_iterator_new(array, array + 9, int_array_next, NULL);
	if (iter == NULL)
		return (ERROR);
	if (lmt_iterator_for_each(iter, int_array_set_42) != NORMAL)
		return (ERROR);
	if (lmt_iterator_for_each(iter, int_array_describe) != NORMAL)
		return (ERROR);
	printf("\n");
	if (lmt_iterator_for_each_enumerated(iter, int_array_set_double_index) != NORMAL)
		return (ERROR);
	if (lmt_iterator_for_each_enumerated(iter, int_array_describe_with_index) != NORMAL)
		return (ERROR);
	lmt_iterator_free(iter);
	return (NORMAL);
}



int	lmt_string_split_test(int argc, char **argv)
{
	t_lmt_string	*string;
	t_lmt_string	*head_string;

	(void)argc;
	(void)argv;
	string = lmt_string_new("Hello, World!");
	if (string == NULL)
		return (ERROR);
	printf("string -> [%s] as %%s \n", string->str);
	head_string = lmt_string_remove_first(string, 5);
	if (head_string == NULL)
		return (ERROR);
	printf("head_string -> [%s] as %%s \n", head_string->str);
	printf("string -> [%s] as %%s \n", string->str);
	lmt_string_free(head_string);
	lmt_string_free(string);
	return (NORMAL);
}

int	lmt_atoi_test(int argc, char **argv)
{
	int	result;
	int	value;

	if (argc != 2)
	{
		printf("Need only 1 argument \n");
		return (NORMAL);
	}
	result = lmt_atoi(argv[1], &value);
	if (result == PARSE_FAILURE)
		printf("Parse failed \n");
	else
		printf("Parse successed: [%d] as %%d \n", value);
	return (NORMAL);
}

int	lmt_string_test(int argc, char **argv)
{
	t_lmt_string	*string;
	t_lmt_string	*head_string;
	t_lmt_string	*second_head_string;
	char			*check_point;

	(void)argc;
	(void)argv;
	string = lmt_string_new("hi, hello!");
	if (string == NULL)
		return (ERROR);
	printf("value -> [%s] as %%s \n", string->str);
	head_string = lmt_string_split(string, ", ");
	if (head_string == NULL)
		return (ERROR);
	printf("head string -> [%s] as %%s \n", head_string->str);
	printf("tail string -> [%s] as %%s \n", string->str);
	if (lmt_string_append_string(head_string, " there!") != NORMAL)
		return (ERROR);
	printf("head string -> [%s] as %%s \n", head_string->str);
	if (lmt_string_append_lmt_string(head_string, head_string) != NORMAL)
		return (ERROR);
	printf("head string -> [%s] as %%s \n", head_string->str);
	check_point = lmt_str_first_str(head_string->str, "t");
	if (check_point == NULL)
		return (ERROR);
	printf("check point -> [%s] as %%s \n", check_point);
	check_point = lmt_str_last_str(head_string->str, "t");
	if (check_point == NULL)
		return (ERROR);
	printf("check point -> [%s] as %%s \n", check_point);
	second_head_string = lmt_string_split(head_string, "!");
	if (second_head_string == NULL)
		return (ERROR);
	printf("second head string -> [%s] as %%s \n", second_head_string->str);
	printf("head string -> [%s] as %%s \n", head_string->str);
	lmt_string_free(string);
	lmt_string_free(head_string);
	lmt_string_free(second_head_string);
	return (NORMAL);
}



//	static void	add_one(void *content)
//	{
//		++*(int *)content;
//	}
//	
//	static void	print_int(void *content)
//	{
//		printf("*(int *)content: %d \n", *(int *)content);
//	}
//	
//	void	lmt_sequence_test()
//	{
//		int	a;
//		int	b;
//		int	c;
//		t_lmt_sequence	*sequence;
//	
//		a = 1;
//		b = 2;
//		c = 3;
//		sequence = lmt_sequence_new();
//		lmt_sequence_insert_first(sequence, &a);
//		lmt_sequence_append(sequence, &b);
//		lmt_sequence_insert_first(sequence, &c);
//	
//		lmt_sequence_iterate(sequence, print_int);
//		lmt_sequence_iterate(sequence, add_one);
//		lmt_sequence_iterate(sequence, print_int);
//	
//		int	*p_c = lmt_sequence_pop_first(sequence);
//		printf("Poped value: %d \n", *p_c);
//		lmt_sequence_iterate(sequence, print_int);
//		lmt_sequence_free(sequence, NULL);
//	}



int	main(int argc, char **argv)
{
	int	return_value;

	return_value = EXECUTE(argc, argv);
	if (return_value != NORMAL)
		printf("Error occured: [%d]\n", return_value);
	return (return_value);
}
