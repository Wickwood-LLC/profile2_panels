<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('Profile2 revision'),
  'description' => t('Revision settings fields of profile2 form.'),
  'required context' => new ctools_context_required(t('Form'), 'profile2_edit_form'),
  'category' => t('Form'),
);

function profile2_panels_profile2_revision_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('profile2');

  $block->title = '';
  $block->delta = 'revision_information';

  if (isset($context->form)) {
    $block->content = array();
    $block->content['revision_information'] = isset($context->form['revision_information']) ? $context->form['revision_information'] : NULL;
    unset($context->form['revision_information']);
  }
  else {
    $block->content = t('Profile2 revision.');
  }
  return $block;
}

function profile2_panels_profile2_revision_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" profile2 revision', array('@s' => $context->identifier));
}

function profile2_panels_profile2_revision_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
