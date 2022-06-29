/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:03:25 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/28 22:10:25 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H
//----------------------------------- tokens
# define RIP 1 // <
# define ROP 2 // >
# define PIPE 3 // PIPE | 
# define HEREDOC  4 // <<
# define APND 5 // >>
# define SIMPLE_CMD 6 // COMMAND WORD
# define EXIT_STATUS 7 // EXIR STATUS
# define CMD 8 //cmd
// //--------------------------------------------- build in commands
// # define ECHO 11 // echo command 
// # define CD 12 // cd command 
// # define  PWD 13 // PWD  COMMAD
// # define  EXPORT 14 // EXPORT  COMMAD
// # define  UNSET 15 // UNSET  COMMAD
// # define  ENV 16 // ENV  COMMAD
// # define  EXIT 17 // EXIT  COMMAD
#endif

//	TODO : 
// moraj3a lga3 tests
//split command in 2d array list
//expande data in list of cmds
// norme
// ngol ali check lexer part
//--------------------------------------------
	// count the number of words I have in the table 
	// alloc for those words
	// fill table of 2d array with those words
	// expande the 2d array table