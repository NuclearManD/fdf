/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:21:15 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/04 15:21:15 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main()//int ac, char **av)
{
	t_mlx	mlx; //Here I first create my struct that will contains all the "MLX stuff"
	t_img	img;
	int		count_w;
	int		count_h;

	count_h = -1;
	//First you need to call mlx_init and store its return value.
	mlx.mlx_ptr = mlx_init();
	//Now do the same with mlx_new_window
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "¥¥†®¥∑®†ß¥®´√ç¥¨†ç∆†®ƒƒ©√¨ˆ˚˙ˆ√ƒ∆˚¥©∆˙©ç∂≈¨§®∂†¥®å∞¥¢©©¨¥∂ƒ∂¨∆˙≤çøˆ¨†©ø¬ˆ∆¨†©¶®ˆø…¨†¥®¨¬¥∂ˆ¥†¨√çƒ§∞ß∂´®†ªø¨∆ƒ©˜µ∆∫˙ƒ∂¨˚√ƒ");
	//One more time with mlx_new_image
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	/*
	 Now the important part :
	 mlx_get_data_addr will return a char* that is 4 times the (width * height) of your image.
	 Why so ? Let me explain : This char* will represent your image, pixel by pixel,
	 and the values of this array are the colors. That's why the array is 4 times bigger :
	 you need 4 char to code the color of each pixels (one for Red, Green and Blue) and one for the alpha.
	 But... it's not very convenient, right ? So here is my little trick : you cast
	 mlx_get_data_addr as an int* and store it in an int*.
	 This way, the array will have the exact same size as your window, and each index
	 will represent one complete color of a pixel !
	*/
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
		&img.endian);
	/*
	 Now just a little example : here is a loop that will draw each pixels that
	 have an odd width in white and the ones that have an even width in black.
	*/
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			//if (count_w % 2)
				/*
				 As you can see here instead of using the mlx_put_pixel function
				 I just assign a color to each pixel one by one in the image,
				 and the image will be printed in one time at the end of the loop.
				 Now one thing to understand here is that you're working on a 1-dimensional
				 array, while your window is (obviously) 2-dimensional.
				 So, instead of having data[height][width] here you'll have the following
				 formula : [current height * max width + current width] (as you can see below)
				*/
				img.data[count_h * WIN_WIDTH + count_w] = (count_h * 15 + count_w) * 17;
			//else
			//	img.data[count_h * WIN_WIDTH + count_w] = 0;
		}
	}
	//Now you just have to print the image using mlx_put_image_to_window !
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
	
	/*img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	/ *
	 Now the important part :
	 mlx_get_data_addr will return a char* that is 4 times the (width * height) of your image.
	 Why so ? Let me explain : This char* will represent your image, pixel by pixel,
	 and the values of this array are the colors. That's why the array is 4 times bigger :
	 you need 4 char to code the color of each pixels (one for Red, Green and Blue) and one for the alpha.
	 But... it's not very convenient, right ? So here is my little trick : you cast
	 mlx_get_data_addr as an int* and store it in an int*.
	 This way, the array will have the exact same size as your window, and each index
	 will represent one complete color of a pixel !
	*/
	/*img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
		&img.endian);
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			//if (count_w % 2)
				/ *
				 As you can see here instead of using the mlx_put_pixel function
				 I just assign a color to each pixel one by one in the image,
				 and the image will be printed in one time at the end of the loop.
				 Now one thing to understand here is that you're working on a 1-dimensional
				 array, while your window is (obviously) 2-dimensional.
				 So, instead of having data[height][width] here you'll have the following
				 formula : [current height * max width + current width] (as you can see below)
				*/
	/*			img.data[count_h * WIN_WIDTH + count_w] = (count_h * 15 + count_w) * 17;
			//else
			//	img.data[count_h * WIN_WIDTH + count_w] = 0;
		}
	}
	//Now you just have to print the image using mlx_put_image_to_window !
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);*/
	mlx_loop(mlx.mlx_ptr);
	return (0);
}