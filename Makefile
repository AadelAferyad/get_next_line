NAME := get_next_line.a
COMPILER := cc
FLAGS := -Wall -Werror -Wextra
REMOVE := rm -f

src = get_next_line.c get_next_line_utils.c
src_bonus = get_next_line_bonus.c get_next_line_utils_bonus.c

obj = $(src:%.c=%.o)
obj_bonus = $(src_bonus:%.c=%.o)

all : $(NAME)


$(NAME) : $(obj)
	ar rcs $(NAME) $(obj)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

bonus: $(obj_bonus)
	ar rcs $(NAME) $(obj_bonus)

clean:
	$(REMOVE) $(obj) $(obj_bonus)

fclean: clean
	$(REMOVE) $(NAME)
