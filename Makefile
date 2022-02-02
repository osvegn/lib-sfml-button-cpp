NAME		=	libsfmlbutton.a

RM			=	rm -rf

SOURCES		=	sources/button/Button.cpp 			\

HEADERS		=	sources/interface/IButton.hpp 		\
				sources/button/Button.hpp 			\

OBJECTS		=	$(SOURCES:.cpp=.o)

CXXFLAGS	=	-I ./includes

$(NAME): move_headers $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

move_headers:
	cp $(HEADERS) ./includes/

all:	$(NAME)

clean:
	$(RM) $(OBJECTS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: re fclean clean all