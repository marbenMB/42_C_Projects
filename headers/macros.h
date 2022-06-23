/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:03:25 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/22 22:12:43 by abellakr         ###   ########.fr       */
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
# define CMD 8 
// //--------------------------------------------- build in commands
// # define ECHO 11 // echo command 
// # define CD 12 // cd command 
// # define  PWD 13 // PWD  COMMAD
// # define  EXPORT 14 // EXPORT  COMMAD
// # define  UNSET 15 // UNSET  COMMAD
// # define  ENV 16 // ENV  COMMAD
// # define  EXIT 17 // EXIT  COMMAD
#endif


//	TODO : !!! Check exit status in new lexer algo