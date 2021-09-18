#include <stdlib.h>
#include "t_lmt_sequence_element.h"
#include "lmt_util.h"

//	stdlib.h: free()

static t_lmt_sequence_element	*lmt_sequence_element_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_sequence_element)));
}

static void	lmt_sequence_element_init(t_lmt_sequence_element *element, void *content)
{
	element->content = content;
}

t_lmt_sequence_element	*lmt_sequence_element_new(void *content)
{
	t_lmt_sequence_element	*element;

	element = lmt_sequence_element_alloc();
	lmt_sequence_element_init(element, content);
	return (element);
}

void	lmt_sequence_element_free(t_lmt_sequence_element *element, t_lmt_sequence_appliance content_free)
{
	if (content_free != NULL)
		content_free(element->content);
	free(element);
}

void	*lmt_sequence_element_pop(t_lmt_sequence_element *element)
{
	void	*content;

	content = element->content;
	free(element);
	return (content);
}
