#Name of the program of the library

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Compilers and flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories

INCDIR = .
SRCDIR = .

# SERVER_SRCS

SERVER_SRCS =	$(SRCDIR)/server.c\
	        $(SRCDIR)/utils.c\
		$(SRCDIR)/ft_printf.c\
		$(SRCDIR)/parse_format.c\
		$(SRCDIR)/handle_specifier.c\
		$(SRCDIR)/print_char.c\
		$(SRCDIR)/print_str.c\
		$(SRCDIR)/print_percentage.c\
		$(SRCDIR)/convert_int_to_str.c

# CLIENT_SRCS

CLIENT_SRCS = 	$(SRCDIR)/client.c\
		$(SRCDIR)/utils.c\
		$(SRCDIR)/ft_printf.c\
		$(SRCDIR)/parse_format.c\
		$(SRCDIR)/handle_specifier.c\
		$(SRCDIR)/print_char.c\
		$(SRCDIR)/print_str.c\
		$(SRCDIR)/print_percentage.c\
		$(SRCDIR)/convert_int_to_str.c

# CLIENT_BONUS_SRCS

CLIENT_BONUS_SRCS =  $(SRCDIR)/client_bonus.c\
		     $(SRCDIR)/utils_bonus.c\
		     $(SRCDIR)/ft_printf.c\
		     $(SRCDIR)/parse_format.c\
		     $(SRCDIR)/handle_specifier.c\
		     $(SRCDIR)/print_char.c\
		     $(SRCDIR)/print_str.c\
		     $(SRCDIR)/print_percentage.c\
		     $(SRCDIR)/convert_int_to_str.c

# SERVER_BONUS_OBJS

SERVER_BONUS_SRCS = $(SRCDIR)/server_bonus.c\
		    $(SRCDIR)/utils_bonus.c\
		    $(SRCDIR)/ft_printf.c\
		    $(SRCDIR)/parse_format.c\
		    $(SRCDIR)/handle_specifier.c\
		    $(SRCDIR)/print_char.c\
		    $(SRCDIR)/print_str.c\
		    $(SRCDIR)/print_percentage.c\
		    $(SRCDIR)/convert_int_to_str.c

# SERVER_OBJS

SERVER_OBJS = $(SERVER_SRCS:$(SRCDIR)/%.c=%.o)

# CLIENT_OBJS

CLIENT_OBJS = $(CLIENT_SRCS:$(SRCDIR)/%.c=%.o)

# SERVER_BONUS_OBJS

SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:$(SRCDIR)/%.c=%.o)

# CLIENT_BONUS_OBJS

CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:$(SRCDIR)/%.c=%.o)

# Main

all: $(SERVER) $(CLIENT)

# Bonus

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

# Main rules

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -I $(INCDIR) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -I $(INCDIR) -o $(CLIENT)

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) -I $(INCDIR) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) -I $(INCDIR) -o $(CLIENT_BONUS)

# clear

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

# full clear

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

# restart

re: fclean all

.PHONY: fclean all re clean bonus
