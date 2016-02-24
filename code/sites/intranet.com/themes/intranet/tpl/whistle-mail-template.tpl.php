<html>
				<head>
					<meta content="text/html; charset=utf-8" http-equiv="Content-Type">
					<title>Intranet.org</title>
				</head>
				<body bgcolor="#ffffff" style="margin:0px;padding:20px;">    
					<table border="0" cellpadding="0" cellspacing="0" width="800" align="center">
						
						<tr>
							<td>
								<table style="border:8px solid #D3D9DE" cellpadding="20">
									<tr>
										<td colspan="3">
											Dear Whistle Blower Team,
											
											<p>Department:-<?php print $params['department'];?></p>
											<p>Comment:-<?php print $params['comment']; ?></p>
											
											<p>Regards,</p>
											<p><?php print $params['user_name']; ?></p>
										</td>
									</tr>
									<!--<tr>
										<td align="left">
											<a>
												<img align="center" src="http://<?php print $params['base_url']; ?>/images/logo.png" alt="sakal Logo" width="231" >
											</a>
										</td>
									</tr>-->
								</table>
							</td>
						</tr>
						
					</table>
				</body>
			</html>