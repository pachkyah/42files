/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:18:11 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/01 02:38:51 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

// Character checks
int	ft_isalpha(int c);	// Checks if character is alphabetic
int	ft_isdigit(int c);	// Checks if character is a digit (0–9)
int	ft_isalnum(int c);	// Checks if character is alphanumeric
int	ft_isascii(int c);	// Checks if character is ASCII (0–127)
int	ft_isprint(int c);	// Checks if character is printable

// String length
size_t	ft_strlen(const char *str);	// Returns length of null-terminated string

// Memory operations
void	*ft_memset(void *b, int c, size_t len);     // Fills memory with byte
void	ft_bzero(void *s, size_t n);                // Sets memory to zero
void	*ft_memcpy(void *dest, const void *src, size_t n);    // Copies memory (no overlap)
void	*ft_memmove(void *dest, const void *src, size_t n); // Safe memory copy with overlap
void	*ft_memchr(const void *s, int c, size_t n);          // Search byte in memory
int	ft_memcmp(const void *s1, const void *s2, size_t n); // Compare memory areas

// String operations
size_t	ft_strlcpy(char *dest, const char *src, size_t size); // Safe string copy
size_t	ft_strlcat(char *dest, const char *src, size_t size); // Safe string concat
char	*ft_strchr(const char *str, int c);       // Find first occurrence of char
char	*ft_strrchr(const char *str, int c);      // Find last occurrence of char
int	ft_strncmp(const char *s1, const char *s2, size_t n); // Compare strings up to n chars
char	*ft_strnstr(const char *hay, const char *needle, size_t len); // Locate substring

// Case conversion
int	ft_toupper(int c);     // Converts to uppercase
int	ft_tolower(int c);     // Converts to lowercase

// Conversions and allocation
int     ft_atoi(const char *str);  // Convert ASCII string to int
void    *ft_calloc(size_t num, size_t size); // Allocates zero-initialized memory
char    *ft_strdup(const char *s);            // Duplicates a string

#endif